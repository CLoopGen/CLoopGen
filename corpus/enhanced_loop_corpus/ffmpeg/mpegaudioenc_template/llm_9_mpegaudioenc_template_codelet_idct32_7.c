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
    tab[idx1] = tab[idx1] + xr;

    xr = (((int64_t)tab[2 + idx1] * (int64_t)xp[1]) >> 15);
    tab[2 + idx1] = tab[idx3] - xr;
    tab[idx3] = tab[idx3] + xr;

    xr = (((int64_t)tab[31 - idx1] * (int64_t)xp[0]) >> 15);
    tab[31 - idx1] = tab[1 + idx1] - xr;
    tab[1 + idx1] = tab[1 + idx1] + xr;

    xr = (((int64_t)tab[3 + idx1] * (int64_t)xp[1]) >> 15);
    tab[3 + idx1] = tab[idx4] - xr;
    tab[idx4] = tab[idx4] + xr;

    xp += 2;

    // Unrolled second iteration manually to reduce loop overhead
    if (i == 0) {
        i++;
        idx1 = i * 4;
        idx2 = 30 - idx1;
        idx3 = 28 - idx1;
        idx4 = 29 - idx1;

        xr = (((int64_t)tab[idx2] * (int64_t)xp[0]) >> 15);
        tab[idx2] = tab[idx1] - xr;
        tab[idx1] = tab[idx1] + xr;

        xr = (((int64_t)tab[2 + idx1] * (int64_t)xp[1]) >> 15);
        tab[2 + idx1] = tab[idx3] - xr;
        tab[idx3] = tab[idx3] + xr;

        xr = (((int64_t)tab[31 - idx1] * (int64_t)xp[0]) >> 15);
        tab[31 - idx1] = tab[1 + idx1] - xr;
        tab[1 + idx1] = tab[1 + idx1] + xr;

        xr = (((int64_t)tab[3 + idx1] * (int64_t)xp[1]) >> 15);
        tab[3 + idx1] = tab[idx4] - xr;
        tab[idx4] = tab[idx4] + xr;

        xp += 2;
    }
}
}
