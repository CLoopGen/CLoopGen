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
    // Variant 2: Strided Memory Access with Fixed Offsets
    // Replace variable-based indexing with fixed strides over precomputed offset arrays
    // to simulate a more predictable strided pattern, potentially aiding vectorization.
    const int offsets[4] = {0, 4, 8, 12};  // Base increments
    for (i = 0; i < 4; i++) {
        int off = offsets[i];

        // Use fixed arithmetic patterns: tab[30-off], tab[off], etc.
        xr = (((int64_t)tab[30 - off] * (int64_t)xp[0]) >> 15);
        tab[30 - off] = tab[off] - xr;
        tab[off] = tab[off] + xr;

        xr = (((int64_t)tab[2 + off] * (int64_t)xp[1]) >> 15);
        tab[2 + off] = tab[28 - off] - xr;
        tab[28 - off] = tab[28 - off] + xr;

        xr = (((int64_t)tab[31 - off] * (int64_t)xp[0]) >> 15);
        tab[31 - off] = tab[1 + off] - xr;
        tab[1 + off] = tab[1 + off] + xr;

        xr = (((int64_t)tab[3 + off] * (int64_t)xp[1]) >> 15);
        tab[3 + off] = tab[29 - off] - xr;
        tab[29 - off] = tab[29 - off] + xr;

        xp += 2;
    }
}
