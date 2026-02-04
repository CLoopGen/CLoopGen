#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double a;
extern double s;
extern double F;
extern int64_t m;
extern int64_t y;
extern int64_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory-like access pattern (simulated via index scaling)
    // Though no actual array is present, we simulate strided behavior by modifying the divisor computation
    // to use a stride of 2 on the effective index, skipping every other value logically.
    int64_t stride = 2;
    for (i = y + 1; i <= m; i += stride) {
        if (i <= m) {
            F /= (a / i - s);
        }
        // Handle potential next element in stride (mimic unrolling or vectorization effect)
        int64_t j = i + 1;
        if (j <= m) {
            F /= (a / j - s);
        }
    }
}
