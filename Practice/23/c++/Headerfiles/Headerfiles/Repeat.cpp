#include "repeat.h"
#include "factor.h"
int repeat(int i, int j)
{
	int rep = 0;
	rep = factor(j) / (factor(i) * factor(j -i));
	return rep;
}