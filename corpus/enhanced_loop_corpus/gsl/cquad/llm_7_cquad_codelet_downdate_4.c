#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  double bee[68];
extern int n;
extern int d;
extern  int bidx[4];
extern double b_new[34];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 1; i <= n + 1; i++)
        b_new[i] = b_new[i-1] + (bee[bidx[d] + i] - bee[bidx[d] + i - 1]);
    if (n >= 0)
        b_new[0] = bee[bidx[d]];
}
