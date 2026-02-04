#include <stdio.h>

#include <inttypes.h>

extern int mark[7056];
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with reversed iteration order and fixed stride
    // Access elements with a constant stride across rows, iterating backwards
    const int stride = 4 * 21;
    for (j = 21 * 3 - 1; j >= 21; j--) {
        for (i = 21 * 3 - 1; i >= 21; i--) {
            mark[(4 * 21 * i + j)] = 0;
        }
    }
}
