#include <stdio.h>

#include <inttypes.h>

typedef unsigned char UChar;

typedef struct {
    UChar b[8];
} UInt64;

typedef int Int32;

extern UInt64 *n;
extern Int32 i;
extern double base;
extern double sum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reduced trip count with higher operation density per iteration using bit manipulation simulation
    sum = 0.0;
    base = 1.0;
    for (i = 0; i < 4; i++) {  // Half the iterations, process two bytes per loop with fused operations
        double combined = (double)(n->b[2*i]) + 256.0 * (double)(n->b[2*i + 1]);
        sum += base * combined;
        base *= 65536.0;  // Equivalent to multiplying by 256^2
    }
}
