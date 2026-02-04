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
    for (i = 0; i < 4; i++) {
        int idx1 = i * 4;
        int idx2 = 28 - i * 4;
        int idx3 = 29 - i * 4;
        int idx4 = 30 - i * 4;
        int idx5 = 31 - i * 4;

        int64_t prod1 = ((int64_t)tab[idx4] * (int64_t)xp[0]) >> 15;
        int64_t prod2 = ((int64_t)tab[2 + idx1] * (int64_t)xp[1]) >> 15;
        int64_t prod3 = ((int64_t)tab[idx5] * (int64_t)xp[0]) >> 15;
        int64_t prod4 = ((int64_t)tab[3 + idx1] * (int64_t)xp[1]) >> 15;

        int val_a = tab[idx1];
        int val_b = tab[idx2];
        int val_c = tab[1 + idx1];
        int val_d = tab[idx3];

        tab[idx4] = val_a - prod1;
        tab[idx1] = val_a + prod1;

        tab[2 + idx1] = val_b - prod2;
        tab[idx2] = val_b + prod2;

        tab[idx5] = val_c - prod3;
        tab[1 + idx1] = val_c + prod3;

        tab[3 + idx1] = val_d - prod4;
        tab[idx3] = val_d + prod4;

        xp += 2;
    }
}
