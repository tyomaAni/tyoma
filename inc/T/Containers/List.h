/*
BSD 2-Clause License

Copyright (c) 2025, tyomaAni
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright notice, this
   list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright notice,
   this list of conditions and the following disclaimer in the documentation
   and/or other materials provided with the distribution.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/
#pragma once
#ifndef _TY_LST_H_
#define _TY_LST_H_

template<typename _type>
struct tListNode
{
	tListNode() :m_left(0), m_right(0) {}
	~tListNode() {}
	_type m_data;
	tListNode* m_left;
	tListNode* m_right;
};

// circular double linked list
template<typename _type>
class tList
{
	tList(const tList& other) {};
	tList(tList&& other) {};
public:
	tList() :m_head(0) {}
	~tList() 
	{
		Clear();
	}

	tListNode<_type>* Find(const _type& data)
	{
		if (!m_head)
			return 0;

		auto node = m_head;
		auto last = m_head->m_left;
		while (true)
		{
			if (node->m_data == data)
				return node;

			if (node == last)
				break;
			node = node->m_right;
		}
		return 0;
	}

	void Clear()
	{
		if (!m_head)
			return;
		auto last = m_head->m_left;
		while (true)
		{
			auto next = m_head->m_right;
			m_head->~tListNode();
			tMemory::Free(m_head);

			if (m_head == last)
				break;
			m_head = next;
		}
		m_head = nullptr;
	}


	tListNode<_type>* InsertAfter(const _type& after_this, const _type& data) 
	{
		tListNode<_type>* node = (tListNode<_type>*)tMemory::Malloc(sizeof(tListNode<_type>));
		new(node)tListNode<_type>();

		node->m_data = data;

		if (!m_head)
		{
			m_head = node;
			m_head->m_right = m_head;
			m_head->m_left = m_head;
		}
		else
		{
			auto c = m_head;
			auto l = c->m_left;
			while (true)
			{
				if (c->m_data == after_this)
				{
					auto r = c->m_right;

					node->m_left = c;
					node->m_right = r;

					c->m_right = node;
					r->m_left = node;

					return node;
				}

				if (c == l)
					break;
				c = c->m_right;
			}

			auto last = m_head->m_left;
			last->m_right = node;
			node->m_left = last;
			node->m_right = m_head;
			m_head->m_left = node;
		}
		return node;
	}

	tListNode<_type>* InsertBefore(const _type& after_this, const _type& data)
	{
		tListNode<_type>* node = (tListNode<_type>*)tMemory::Malloc(sizeof(tListNode<_type>));
		new(node)tListNode<_type>();

		node->m_data = data;

		if (!m_head)
		{
			m_head = node;
			m_head->m_right = m_head;
			m_head->m_left = m_head;
		}
		else
		{
			auto c = m_head;
			auto l = c->m_left;
			while (true)
			{
				if (c->m_data == after_this)
				{
					auto l = c->m_left;

					node->m_left = l;
					node->m_right = c;

					c->m_left = node;
					l->m_right = node;

					return node;
				}

				if (c == l)
					break;
				c = c->m_right;
			}

			auto last = m_head->m_left;
			last->m_right = node;
			node->m_left = last;
			node->m_right = m_head;
			m_head->m_left = node;
		}
		return node;
	}

	tListNode<_type>* PushBack(const _type& data)
	{
		tListNode<_type>* node = (tListNode<_type>*)tMemory::Malloc(sizeof(tListNode<_type>));
		new(node)tListNode<_type>();

		node->m_data = data;

		if (!m_head)
		{
			m_head = node;
			m_head->m_right = m_head;
			m_head->m_left = m_head;
		}
		else
		{
			auto last = m_head->m_left;
			last->m_right = node;
			node->m_left = last;
			node->m_right = m_head;
			m_head->m_left = node;
		}
		return node;
	}

	tListNode<_type>* PushFront(const _type& data)
	{
		tListNode<_type>* node = (tListNode<_type>*)tMemory::Malloc(sizeof(tListNode<_type>));
		new(node)tListNode<_type>();

		node->m_data = data;

		if (!m_head)
		{
			m_head = node;
			m_head->m_right = m_head;
			m_head->m_left = m_head;
		}
		else
		{
			node->m_right = m_head;
			node->m_left = m_head->m_left;
			m_head->m_left->m_right = node;
			m_head->m_left = node;
			m_head = node;
		}
		return node;
	}

	void PopFront()
	{
		if (!m_head)
			return;
		auto next = m_head->m_right;
		auto last = m_head->m_left;
		m_head->~tListNode();
		tMemory::Free(m_head);

		if (next == m_head)
		{
			m_head = nullptr;
			return;
		}
		m_head = next;
		next->m_left = last;
		last->m_right = next;
	}

	void PopBack()
	{
		if (!m_head)
			return;

		auto lastNode = m_head->m_left;
		lastNode->m_left->m_right = m_head;
		m_head->m_left = lastNode->m_left;

		lastNode->~tListNode();
		tMemory::Free(lastNode);

		if (lastNode == m_head)
		{
			m_head = nullptr;
		}
	}

	// maybe not correct
	void Erase(tListNode<_type>* node) 
	{
		auto l = node->m_left;
		auto r = node->m_right;
		l->m_right = r;
		r->m_left = l;
		node->~tListNode();
		tMemory::Free(node);
		if (node == m_head)
			m_head = 0;
	}

	bool EraseFirst(const _type& object) 
	{
		if (!m_head)
			return false;

		auto node = m_head;
		auto last = m_head->m_left;
		while (true)
		{
			auto next = node->m_right;
			if (node->m_data == object)
			{
				if (node == m_head)
					pop_front();
				else
				{
					node->m_left->m_right = node->m_right;
					node->m_right->m_left = node->m_left;
					node->~tListNode();
					tMemory::Free(node);

					// ???
					if (node == m_head)
						m_head = 0;
				}
				return true;
			}
			if (node == last)
				break;
			node = next;
		}
		return false;
	}

	void Replace(const _type& oldObject, const _type& newObject)
	{
		if (!m_head)
			return;

		auto node = m_head;
		auto last = m_head->m_left;
		while (true)
		{
			auto next = node->m_right;
			if (node->m_data == oldObject)
			{
				node->m_data = newObject;
				return;
			}
			if (node == last)
				break;
			node = next;
		}
	}

	// ???
	// hard to understand but it works
	void Reverse()
	{
		if (!m_head)
			return;
		tListNode<_type>* tail = m_head->m_left;
		tListNode<_type>* curr = m_head;
		while (true)
		{
			auto l = curr->m_left;
			auto r = curr->m_right;

			curr->m_left = r;
			curr->m_right = l;

			if (curr == tail)
				break;
			curr = r;
		}
		m_head = tail;
	}

	void EraseByNode(tListNode<_type>* object)
	{
		if (!m_head)
			return;

		object->m_left->m_right = object->m_right;
		object->m_right->m_left = object->m_left;

		if (object == m_head)
			m_head = m_head->m_right;

		if (object == m_head)
			m_head = 0;

		object->~tListNode();
		tMemory::Free(object);
	}

	class Iterator
	{
		//	friend class ConstIterator;

		tListNode<_type>* m_node;
		tListNode<_type>* m_nodeEnd;
		bool m_isEnd; // I DON"T KNOW HOW TO DO ALL THIS ITERATORS
	public:
		Iterator() :m_node(0), m_isEnd(true) {}
		Iterator(tListNode<_type>* head) :m_node(head), m_isEnd(false)
		{
			if (!head)
			{
				m_isEnd = true;
			}
			else
			{
				m_nodeEnd = head->m_left;
			}
		}
		~Iterator() {}

		Iterator& operator ++() {
			if (m_node == m_nodeEnd) {
				m_isEnd = true;
			}
			m_node = m_node->m_right;
			return *this;
		}

		bool operator ==(const Iterator& other) const {
			if (m_isEnd != other.m_isEnd) return false;
			return true;
		}
		bool operator !=(const Iterator& other) const {
			if (m_isEnd != other.m_isEnd) return true;
			return false;
		}
		const _type& operator*() {
			return m_node->m_data;
		}
		_type* operator->() {
			return m_node->m_data;
		}
	};

	Iterator begin() {
		return Iterator(m_head);
	}
	Iterator end() {
		return Iterator();
	}

	tListNode<_type>* m_head;
};

#endif
