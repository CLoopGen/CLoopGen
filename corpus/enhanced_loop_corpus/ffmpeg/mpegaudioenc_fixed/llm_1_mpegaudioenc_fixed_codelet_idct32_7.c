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
    for (i = 0; i < 2; i++) { // Reduce outer loop iterations
        for (int step = 0; step < 2; step++) { // Simulate original 4 iterations via inner loop
            int idx = i * 2 + step; // Map to original i index
            xr = (((int64_t)(tab[30 - idx * 4]) * (int64_t)(xp[0])) >> 15);
            tab[30 - idx * 4] = (tab[idx * 4] - xr);
            tab[idx * 4] = (tab[idx * 4] + xr);
            xr = (((int64_t)(tab[2 + idx * 4]) * (int64_t)(xp[1])) >> 15);
            tab[2 + idx * 4] = (tab[28 - idx * 4] - xr);
            tab[28 - idx * 4] = (tab[28 - idx * 4] + xr);
            xr = (((int64_t)(tab[31 - idx * 4]) * (int64_t)(xp[0])) >> 15);
            tab[31 - idx * 4] = (tab[1 + idx * 4] - xr);
            tab[1 + idx * 4] = (tab[1 + idx * 4] + xr);
            xr = (((int64_t)(tab[3 + idx * 4]) * (int64_t)(xp[1])) >> 15);
            tab[3 + idx * 4] = (tab[29 - idx * 4] - xr);
            tab[29 - idx * 4] = (tab[29 - idx * 4] + xr);
            xp += 2;
        }
    }
}
