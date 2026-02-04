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
    // Variant 1: Increased computational intensity with unrolled loop and additional arithmetic operations
    sum = 0.0;
    base = 1.0;
    for (i = 0; i < 8; i += 2) {
        double val1 = (double)(n->b[i]);
        sum += base * val1 + (base * val1 * 0.1);  // Extra computation: 10% damping added
        base *= 256.0;
        
        if (i + 1 < 8) {
            double val2 = (double)(n->b[i + 1]);
            sum += base * val2 + (base * val2 * 0.1);
            base *= 256.0;
        }
    }
}
