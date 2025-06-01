#include "Tyoma.h"
#include "Tyoma/Math.h"

#pragma comment(lib, "Tyoma.Math.lib")
#pragma comment(lib, "Tyoma.Base.lib")

int main()
{
	tyVec2f v;
	v.Set(443.f);

	TY_ASSERT_ST(1 == 2);

	return 1;
}
