#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int INTFLOAT;

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
    // Variant 2: Reduced computational load with increased trip count via splitting each original operation into separate iterations
    // Simulate higher trip count by processing each term in a separate phase
    int total_iterations = n2 * 4;
    for (i = 0; i < total_iterations; i++) {
        int idx = i % n2;
        int phase = i / n2;

        int64_t product;
        int shift_val = 31;
        INTFLOAT sign = 1;

        if (phase == 0) {
            product = (int64_t)(buf[idx]) * (window[idx + n2 - n4]);
        } else if (phase == 1) {
            product = (int64_t)(-saved[n - 1 - idx]) * (window[idx + n2 + n - n4]);
        } else if (phase == 2) {
            product = (int64_t)(-saved[n + idx]) * (window[idx + n2 + 2 * n - n4]);
        } else { // phase == 3
            product = (int64_t)(saved[2 * n + n - 1 - idx]) * (window[idx + n2 + 3 * n - n4]);
        }

        int result = (int)((product + 1073741824) >> shift_val);

        // Accumulate results using out as temporary storage for partial sums
        if (phase == 0) {
            out[n4 + idx] = result;  // First term
        } else {
            out[n4 + idx] += result; // Add subsequent terms
        }
    }
}
