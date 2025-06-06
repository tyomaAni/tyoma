﻿#include "T.h"
#include "T/Math.h"
#include "T/String.h"
#include "T/SysWindow.h"

#pragma comment(lib, "T.Math.lib")
#pragma comment(lib, "T.Base.lib")
#pragma comment(lib, "T.String.lib")

int main()
{
	tVec2f v;
	v.Set(tMath::DegToRad(443.f));

	tStringA stra;
	stra.Append("test");

	tString str;
	str.Append(stra.C_Str());


	tStringW strw;
	str.ToUtf16(strw);

	return 1;
}
