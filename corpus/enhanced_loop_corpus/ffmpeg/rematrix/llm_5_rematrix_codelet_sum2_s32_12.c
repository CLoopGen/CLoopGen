#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

extern int32_t *out;
extern  int32_t *in1;
extern  int32_t *in2;
extern integer len;
extern int i;
extern int64_t coeff1;
extern int64_t coeff2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < len; i++) {
        int64_t term1 = coeff1 * in1[i];
        int64_t term2 = coeff2 * in2[i];
        int64_t sum = term1 + term2;

        // Introduce control dependency: skip update if both inputs are zero
        if (in1[i] == 0 && in2[i] == 0) {
            out[i] = 0;
            continue;
        }

        out[i] = (sum + 16384) >> 15;
    }
}
