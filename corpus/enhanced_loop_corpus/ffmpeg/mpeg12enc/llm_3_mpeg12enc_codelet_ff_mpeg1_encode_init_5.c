#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t fcode_tab[8193];
extern int f_code;
extern int mv;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access
    // Instead of dense filling, write values with a fixed stride (e.g., every 2nd element)
    // This changes spatial locality and simulates sparse update pattern.
    // We maintain logical equivalence in terms of which f_code maps to which mv region,
    // but access memory non-consecutively.

    for (f_code = 7; f_code > 0; f_code--) {
        int range = (8 << f_code);
        for (mv = -range; mv < range; mv += 2) {  // Stride of 2 in mv
            fcode_tab[mv + 4096] = f_code;
            // Also set the next element to maintain density if needed, but here we skip
        }
        // Fill in the odd offsets in a second pass within same f_code to simulate strided write pattern
        for (mv = -range + 1; mv < range; mv += 2) {
            fcode_tab[mv + 4096] = f_code;
        }
    }
}
