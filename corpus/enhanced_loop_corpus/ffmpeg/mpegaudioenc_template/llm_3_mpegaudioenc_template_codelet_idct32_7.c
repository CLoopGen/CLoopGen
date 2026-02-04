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
    // Variant 2: Strided Memory Access Pattern with Reverse Traversal
    // Modify access pattern to use negative strides and reverse loop order
    // This changes temporal and spatial locality, simulating strided access behavior.
    for (i = 3; i >= 0; i--) {
        int forward_idx = i * 4;
        int backward_idx = 30 - i * 4;
        int offset_parity_even = 2 + i * 4;
        int offset_parity_even_sym = 28 - i * 4;
        int offset_odd_high = 31 - i * 4;
        int offset_odd_low = 1 + i * 4;
        int offset_three = 3 + i * 4;
        int offset_three_sym = 29 - i * 4;

        // First butterfly using xp[0]
        xr = (((int64_t)tab[backward_idx] * (int64_t)xp[0]) >> 15);
        tab[backward_idx] = tab[forward_idx] - xr;
        tab[forward_idx] += xr;

        // Second using xp[1] on adjacent even offsets
        xr = (((int64_t)tab[offset_parity_even] * (int64_t)xp[1]) >> 15);
        tab[offset_parity_even] = tab[offset_parity_even_sym] - xr;
        tab[offset_parity_even_sym] += xr;

        // Third with high odd index
        xr = (((int64_t)tab[offset_odd_high] * (int64_t)xp[0]) >> 15);
        tab[offset_odd_high] = tab[offset_odd_low] - xr;
        tab[offset_odd_low] += xr;

        // Fourth with next odd index
        xr = (((int64_t)tab[offset_three] * (int64_t)xp[1]) >> 15);
        tab[offset_three] = tab[offset_three_sym] - xr;
        tab[offset_three_sym] += xr;

        xp += 2;
    }
}
