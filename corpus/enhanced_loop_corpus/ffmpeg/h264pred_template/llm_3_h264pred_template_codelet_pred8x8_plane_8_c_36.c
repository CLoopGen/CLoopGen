#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int k;
extern int stride;
extern  uint8_t * src0;
extern  uint8_t *src1;
extern  uint8_t *src2;
extern int H;
extern int V;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access via index array (induction variable)
    // Introduce an array of indices to create indirect addressing pattern
    // This changes memory access to non-sequential, potentially modeling sparse or irregular patterns

    int indices[] = {2, 3, 4};  // control the loop iteration indirectly
    int num_iters = sizeof(indices) / sizeof(indices[0]);

    uint8_t *temp_src1 = src1;
    uint8_t *temp_src2 = src2;

    for (int i = 0; i < num_iters; ++i) {
        int k_val = indices[i];

        temp_src1 += stride;
        temp_src2 -= stride;

        // Indirect access through k_val as index into src0
        H += k_val * (src0[k_val] - src0[-k_val]);
        V += k_val * (temp_src1[0] - temp_src2[0]);
    }
}
