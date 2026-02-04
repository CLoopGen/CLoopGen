#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t fcode_tab[8193];
extern int f_code;
extern int mv;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with reversed iteration order
    // Instead of accessing mv in negative and positive ranges, we rewrite the loop to traverse the array consecutively.
    // We precompute the index range and fill fcode_tab in forward order.

    int start = -(8 << 7) + 4096;
    int end = (8 << 7) + 4096;

    for (f_code = 7; f_code > 0; f_code--) {
        int shift = 8 << f_code;
        start = -shift + 4096;
        end = shift + 4096;
        for (int idx = start; idx < end; idx++) {
            fcode_tab[idx] = f_code;
        }
    }
}
