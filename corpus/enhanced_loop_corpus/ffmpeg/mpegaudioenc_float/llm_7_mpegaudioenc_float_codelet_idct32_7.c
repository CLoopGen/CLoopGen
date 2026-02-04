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
xr = 0;
for (i = 0; i < 4; i++) {
    int temp_val1 = tab[30 - i * 4];
    int temp_val2 = tab[2 + i * 4];
    int temp_val3 = tab[31 - i * 4];
    int temp_val4 = tab[3 + i * 4];
    int coef0 = xp[0];
    int coef1 = xp[1];
    int update1 = (((int64_t)temp_val1 * (int64_t)coef0) >> 15);
    int update2 = (((int64_t)temp_val2 * (int64_t)coef1) >> 15);
    int update3 = (((int64_t)temp_val3 * (int64_t)coef0) >> 15);
    int update4 = (((int64_t)temp_val4 * (int64_t)coef1) >> 15);
    tab[30 - i * 4] = tab[i * 4] - update1 + xr;
    tab[i * 4] = tab[i * 4] + update1;
    tab[2 + i * 4] = tab[28 - i * 4] - update2 + xr;
    tab[28 - i * 4] = tab[28 - i * 4] + update2;
    tab[31 - i * 4] = tab[1 + i * 4] - update3 + xr;
    tab[1 + i * 4] = tab[1 + i * 4] + update3;
    tab[3 + i * 4] = tab[29 - i * 4] - update4 + xr;
    tab[29 - i * 4] = tab[29 - i * 4] + update4;
    xr = update1 ^ update2 ^ update3 ^ update4;
    xp += 2;
}
}
