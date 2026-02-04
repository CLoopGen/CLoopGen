#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t fcode_tab[8193];
extern int f_code;
extern int mv;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with reversed order and stride of 2
    for (f_code = 7; f_code > 0; f_code--) {
        int shift = 16 << f_code;
        int start = -shift + 4096;
        int end = shift + 4096;
        // Write only even indices in reverse to create strided, consecutive-like pattern
        for (mv = end - 1; mv >= start; mv--) {
            if ((mv - 4096) % 2 == 0) {
                fcode_tab[mv] = f_code;
            }
        }
    }
}
