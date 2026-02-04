#include <stdio.h>

#include <inttypes.h>

extern int *dig;
extern int *chr;
extern int length;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2 (backward traversal)
    for (j = length - 2; j >= 0; j -= 2) {
        *chr = *chr * 10 + dig[j];
        if (j > 0) {
            *chr = *chr * 10 + dig[j-1];
        }
    }
}
