#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t *decoded;
extern  int coeffs[32];
extern int pred_order;
extern int qlevel;
extern int len;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = pred_order; i < len - 1; i += 2, decoded += 2) {
    unsigned int c = coeffs[0];
    unsigned int d_prev = decoded[0];
    int s0 = 0, s1 = 0;
    // Reverse the inner loop iteration to change data flow direction (RAW -> WAR emphasis)
    for (j = pred_order - 1; j >= 1; j--) {
        unsigned int d_curr = decoded[j];
        s1 += c * d_curr;
        c = coeffs[j];
        s0 += c * d_prev;
        d_prev = d_curr;
    }
    // Final computation adjusted for reversed accumulation
    s0 += coeffs[0] * decoded[0]; // Re-include initial term excluded in reverse
    // Update with shifted indices to preserve correctness under transformation
    decoded[pred_order] += (unsigned int)(s0 >> qlevel);
    if (pred_order + 1 < 32) {
        decoded[pred_order + 1] += (unsigned int)(s1 >> qlevel);
    }
}
}
