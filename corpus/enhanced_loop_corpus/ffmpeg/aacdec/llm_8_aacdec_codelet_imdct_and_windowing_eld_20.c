#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float INTFLOAT;

extern INTFLOAT *out;
extern INTFLOAT *saved;
extern INTFLOAT *buf;
extern int i;
extern  int n;
extern  int n2;
extern  int n4;
extern  INTFLOAT * window;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Increased computational intensity with additional arithmetic and reduced trip count
    for (i = n4; i < n2 - 4; i += 2) {
        INTFLOAT term1 = buf[n2 - 1 - i] * window[i - n4];
        INTFLOAT term2 = saved[i + n2] * window[i + n - n4];
        INTFLOAT term3 = -saved[n + n2 - 1 - i] * window[i + 2 * n - n4];
        INTFLOAT term4 = -saved[2 * n + n2 + i] * window[i + 3 * n - n4];
        INTFLOAT sum = term1 + term2 + term3 + term4;
        // Additional computation to increase intensity
        sum = sum * sum + (term1 * term3) - (term2 * term4);
        out[i - n4] = sum;
        // Unroll second iteration manually
        term1 = buf[n2 - 1 - (i+1)] * window[(i+1) - n4];
        term2 = saved[(i+1) + n2] * window[(i+1) + n - n4];
        term3 = -saved[n + n2 - 1 - (i+1)] * window[(i+1) + 2 * n - n4];
        term4 = -saved[2 * n + n2 + (i+1)] * window[(i+1) + 3 * n - n4];
        sum = term1 + term2 + term3 + term4;
        sum = sum * sum + (term1 * term3) - (term2 * term4);
        out[(i+1) - n4] = sum;
    }
}
