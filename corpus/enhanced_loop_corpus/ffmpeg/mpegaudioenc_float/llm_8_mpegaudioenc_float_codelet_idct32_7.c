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
for (i = 0; i < 8; i++) {
    xr = (((int64_t)(tab[30 - i * 2]) * (int64_t)(xp[0])) >> 15);
    tab[30 - i * 2] = (tab[i * 2] - xr);
    tab[i * 2] = (tab[i * 2] + xr);
    xr = (((int64_t)(tab[2 + i * 2]) * (int64_t)(xp[1])) >> 15);
    tab[2 + i * 2] = (tab[28 - i * 2] - xr);
    tab[28 - i * 2] = (tab[28 - i * 2] + xr);
    xr = (((int64_t)(tab[31 - i * 2]) * (int64_t)(xp[0])) >> 15);
    tab[31 - i * 2] = (tab[1 + i * 2] - xr);
    tab[1 + i * 2] = (tab[1 + i * 2] + xr);
    xr = (((int64_t)(tab[3 + i * 2]) * (int64_t)(xp[1])) >> 15);
    tab[3 + i * 2] = (tab[29 - i * 2] - xr);
    tab[29 - i * 2] = (tab[29 - i * 2] + xr);
    xp += 2;
}
}
