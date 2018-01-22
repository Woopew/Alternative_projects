#include <stdio.h>
#include "is_prime.h"

int prime_pairs(int *pnt_tal)
{
	int testa_tal = *pnt_tal;
	/*int n1 = 3;*/
	 for(int i = 2; i < testa_tal; i++)
            {
                if (testa_tal % i == 0 && i != testa_tal)    
                {
                    return 0;
                }
            }
    return 1;
}
