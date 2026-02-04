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
    int index1 = i * 4;
    int index2 = 30 - index1;
    int index3 = 28 - index1;
    int index4 = 29 - index1;
    int val_a = tab[index2];
    int val_b = tab[index1];
    int val_c = tab[2 + index1];
    int val_d = tab[3 + index1];
    int val_e = tab[31 - index1];
    int val_f = tab[1 + index1];
    int val_g = tab[index3];
    int val_h = tab[index4];
    int prod1 = ((int64_t)val_a * (int64_t)xp[0]) >> 15;
    int prod2 = ((int64_t)val_c * (int64_t)xp[1]) >> 15;
    int prod3 = ((int64_t)val_e * (int64_t)xp[0]) >> 15;
    int prod4 = ((int64_t)val_d * (int64_t)xp[1]) >> 15;
    tab[index2] = val_b - prod1;
    tab[index1] = val_b + prod1;
    tab[2 + index1] = val_g - prod2;
    tab[index3] = val_g + prod2;
    tab[31 - index1] = val_f - prod3;
    tab[1 + index1] = val_f + prod3;
    tab[3 + index1] = val_h - prod4;
    tab[index4] = val_h + prod4;
    xr += prod1 + prod2 + prod3 + prod4;
    xp += 2;
}
}
