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
    // Variant 2: Strided Access with Base Offset and Sequential Indexing
    // Transform all index calculations into a single base pointer progression
    // using a stride of 1 and manually stepping through transformed indices.
    // This variant simulates a more cache-friendly sequential scan by reordering operations.

    int base_offsets[8] = {0, 1, 2, 3, 28, 29, 30, 31}; // frequently accessed columns
    int *temp_tab = (int*)malloc(8 * sizeof(int));
    if (!temp_tab) return;

    // Preload values from scattered locations into a local array for sequential processing
    for (int j = 0; j < 4; j++) {
        temp_tab[0] = tab[30 - j*4]; temp_tab[1] = tab[j*4];
        temp_tab[2] = tab[2 + j*4]; temp_tab[3] = tab[28 - j*4];
        temp_tab[4] = tab[31 - j*4]; temp_tab[5] = tab[1 + j*4];
        temp_tab[6] = tab[3 + j*4]; temp_tab[7] = tab[29 - j*4];

        xr = (((int64_t)temp_tab[0] * (int64_t)xp[0]) >> 15);
        tab[30 - j*4] = temp_tab[1] - xr;
        tab[j*4] = temp_tab[1] + xr;

        xr = (((int64_t)temp_tab[2] * (int64_t)xp[1]) >> 15);
        tab[2 + j*4] = temp_tab[3] - xr;
        tab[28 - j*4] = temp_tab[3] + xr;

        xr = (((int64_t)temp_tab[4] * (int64_t)xp[0]) >> 15);
        tab[31 - j*4] = temp_tab[5] - xr;
        tab[1 + j*4] = temp_tab[5] + xr;

        xr = (((int64_t)temp_tab[6] * (int64_t)xp[1]) >> 15);
        tab[3 + j*4] = temp_tab[7] - xr;
        tab[29 - j*4] = temp_tab[7] + xr;

        xp += 2;
    }

    free(temp_tab);
}
