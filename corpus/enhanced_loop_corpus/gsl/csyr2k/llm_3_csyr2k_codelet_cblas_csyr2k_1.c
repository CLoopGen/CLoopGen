#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern void *C;
extern  int ldc;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with reversed iteration order (j from i down to 0) and manual stride stepping
    float *C_base = (float *)C;
    for (i = 0; i < N; i++) {
        for (j = i; j >= 0; j--) {  // Reverse inner loop direction
            int offset = 2 * (ldc * i + j);
            *(C_base + offset) = 0.0f;
            *(C_base + offset + 1) = 0.0f;
        }
    }
}
