#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef float real;

extern integer *n;
extern real *z__;
extern real *delta;
extern real *work;
extern integer i__1;
extern integer j;
extern real phi;
extern real dphi;
extern real temp;
extern real erretm;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reduced arithmetic operations and increased trip count via split logic
    // Simulate higher trip count by iterating over a logically expanded range (conceptually, e.g., scaled index space)
    // Here we maintain same bounds but insert lightweight auxiliary computation to dilute arithmetic density

    real scale = 1.0f;
    real offset = 0.1f;
    for (j = *n; j >= i__1; --j) {
        // Simplified core operation
        temp = z__[j] / work[j];          // Removed delta[j] from denominator
        phi += z__[j] * temp;
        // Removed dphi update (reduced operation count)
        erretm += phi * scale + offset;   // Added lightweight flops to alter computational profile
        scale += 0.01f;
    }
}
