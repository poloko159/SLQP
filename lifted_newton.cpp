#include "Header.h"

int calculat_g()
{
	real_t g[8 * 20];
	int i, j;
	// g0 = x0
	for (j = 0; j < 8; j++) g[j] = pb_vars.x0[j];
	// g(k+1) = Ak*G(k) +ck
	for (i = 0; i < 19; i++)
	{
		for (j = 0; j < 8; j++)
			g[(i+1) * 8 + j] = g[(i) * 8 + j];
	}



	return 0;

}