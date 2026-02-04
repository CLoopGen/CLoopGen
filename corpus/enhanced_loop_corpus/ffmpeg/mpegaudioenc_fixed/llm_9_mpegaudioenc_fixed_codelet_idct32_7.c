#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int *tab;
extern int i;
extern int xr;
extern  int *xp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 2; i += 1) {
    int idx1 = i * 4;
    int idx2 = 30 - idx1;
    int idx3 = 28 - idx1;
    int idx4 = 29 - idx1;

    xr = (((int64_t)tab[idx2] * (int64_t)xp[0]) >> 15);
    tab[idx2] = tab[idx1] - xr;
    tab[idx1] += xr;

    xr = (((int64_t)tab[idx1 + 2] * (int64_t)xp[1]) >> 15);
    tab[idx1 + 2] = tab[idx3] - xr;
    tab[idx3] += xr;

    xr = (((int64_t)tab[31 - idx1] * (int64_t)xp[0]) >> 15);
    tab[31 - idx1] = tab[idx1 + 1] - xr;
    tab[idx1 + 1] += xr;

    xr = (((int64_t)tab[idx1 + 3] * (int64_t)xp[1]) >> 15);
    tab[idx1 + 3] = tab[idx4] - xr;
    tab[idx4] += xr;

    xp += 2;

    // Unroll second iteration manually to increase computational density
    idx1 += 4;
    idx2 -= 4;
    idx3 -= 4;
    idx4 -= 4;

    xr = (((int64_t)tab[idx2 - 4] * (int64_t)xp[0]) >> 15);
    tab[idx2 - 4] = tab[idx1] - xr;
    tab[idx1] += xr;

    xr = (((int64_t)tab[idx1 + 2] * (int64_t)xp[1]) >> 15);
    tab[idx1 + 2] = tab[idx3 - 4] - xr;
    tab[idx3 - 4] += xr;

    xr = (((int64_t)tab[31 - idx1] * (int64_t)xp[0]) >> 15);
    tab[31 - idx1] = tab[idx1 + 1] - xr;
    tab[idx1 + 1] += xr;

    xr = (((int64_t)tab[idx1 + 3] * (int64_t)xp[1]) >> 15);
    tab[idx1 + 3] = tab[idx4 - 4] - xr;
    tab[idx4 - 4] += xr;

    xp += 2;
}
}
