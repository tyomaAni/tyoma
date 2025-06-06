﻿/*
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
#ifndef _TY_ARR_H_
#define _TY_ARR_H_

// `clear` must do m_size = 0;
template<typename type>
class tArray
{
	size_t m_allocated;
	void reallocate(size_t new_capacity)
	{
		new_capacity += (size_t)ceilf((float)m_allocated * 0.5f);
		auto tmp_size = new_capacity * sizeof(type);
		pointer new_data = static_cast<type*>(tMemory::Malloc(tmp_size));
		memset(new_data, 0, tmp_size);

		if (m_data)
		{
			for (size_t i = 0u; i < m_size; ++i)
			{
				new(&new_data[i]) type(m_data[i]);
				(&m_data[i])->~type();
			}
			tMemory::Free(m_data);
		}
		m_data = new_data;
		m_allocated = new_capacity;
	}
public:
	typedef type* pointer;
	typedef type& reference;
	typedef const type& const_reference;

	tArray()
		:
		m_allocated(0),
		m_size(0),
		m_data(0)
	{
	}

	// OK?
	/*tArray(const tArray& other)
		:
		tArray()
	{
		m_allocated = other.m_allocated;
		m_size = other.m_size;

		if (m_allocated)
			reallocate(m_allocated);

		if (m_size)
		{
			for (size_t i = 0u; i < m_size; ++i)
			{
				new(&m_data[i]) type(other.m_data[i]);
				m_data[i] = other.m_data[i];
			}
		}
	}*/

	~tArray()
	{
		FreeMemory();
	}

	const_reference operator[](size_t id) const { return m_data[id]; }
	reference       operator[](size_t id) { return m_data[id]; }

	size_t Capacity()
	{
		return m_allocated;
	}

	size_t Size()
	{
		return m_size;
	}

	void ShrinkToFit()
	{
		auto new_capacity = m_size;
		auto tmp_size = new_capacity * sizeof(type);
		pointer new_data = static_cast<type*>(tMemory::Malloc(tmp_size));
		memset(new_data, 0, tmp_size);

		if (m_data)
		{
			for (size_t i = 0u; i < m_size; ++i)
			{
				new(&new_data[i]) type(m_data[i]);
				(&m_data[i])->~type();
			}
			tMemory::Free(m_data);
		}
		m_data = new_data;
		m_allocated = new_capacity;
	}

	void Reserve(size_t new_capacity)
	{
		if (new_capacity > m_allocated)
			reallocate(new_capacity);
	}

	void Insert(size_t where, const_reference object)
	{
		if (where >= m_size)
		{
			PushBack(object);
		}
		else
		{
			size_t new_size = m_size + 1u;
			if (new_size > m_allocated)
				reallocate(new_size);

			for (size_t i = m_size; i > where;)
			{
				m_data[i] = m_data[i - 1];
				--i;
			}
			new(&m_data[where]) type(object);

			m_size = new_size;
		}
	}

	void PushBack(const_reference object)
	{
		size_t new_size = m_size + 1u;
		if (new_size > m_allocated)
			reallocate(new_size);
		new(&m_data[m_size]) type(object);
		m_size = new_size;
	}

	void PushFront(const_reference object)
	{
		Insert(0, object);
	}

	void FreeMemory()
	{
		if (m_data)
		{
			for (size_t i = 0u; i < m_allocated; ++i)
			{
				(&m_data[i])->~type();
			}
			tMemory::Free(m_data);

			m_allocated = m_size = 0u;
			m_data = nullptr;
		}
	}

	void Clear()
	{
		m_size = 0;
	}

	type* Get(size_t index)
	{
		if (index >= m_allocated)
			return nullptr;

		return &m_data[index];
	}

	/*
	struct _pred
	{
	bool operator() (const Map::renderNode& a, const Map::renderNode& b) const
	{
	return a.m_position.y > b.m_position.y;
	}
	};
	m_renderSprites.sort_insertion(_pred());
	*/
	template<class _Pr>
	void SortInsertion(_Pr _pred)
	{
		size_t i, j;
		type t;
		for (i = 1; i < m_size; ++i)
		{
			for (j = i; j > 0 && _pred(m_data[j - 1], m_data[j]); --j)
			{
				t = m_data[j];
				m_data[j] = m_data[j - 1];
				m_data[j - 1] = t;
			}
		}
	}

	void Erase(size_t index)
	{
		for (size_t i = index; i < m_size; ++i)
		{
			if (i + 1 < m_size)
				m_data[i] = m_data[i + 1];
			else
				m_data[i] = 0;
		}
		if (m_size)
			--m_size;
	}

	void EraseFirst(const_reference ref)
	{
		for (size_t i = 0u; i < m_size; ++i)
		{
			if (m_data[i] == ref)
			{
				erase(i);
				return;
			}
		}
	}

	pointer m_data;
	size_t     m_size;
};


#endif
