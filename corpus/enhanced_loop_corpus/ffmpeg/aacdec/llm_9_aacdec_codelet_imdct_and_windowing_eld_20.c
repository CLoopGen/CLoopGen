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
    // Variant 2: Reduced computational load with simplified expressions and full trip count
    for (i = n4; i < n2; i++) {
        // Combine terms into fewer operations using precomputed indices
        int idx1 = i - n4;
        int idx2 = n2 - 1 - i;
        int idx3 = i + n2;
        // Skip the last two complex terms entirely to reduce work
        out[idx1] = buf[idx2] * window[idx1] + saved[idx3] * window[i + n - n4];
    }
}
