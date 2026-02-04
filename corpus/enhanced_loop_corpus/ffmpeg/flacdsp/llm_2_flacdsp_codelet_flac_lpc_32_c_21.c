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
    for (i = pred_order; i < len; i++, decoded++) {
        int64_t sum = 0;
        // Change to strided memory access: access every second coefficient and mirror index in decoded
        int stride = 2;
        int effective_order = pred_order / stride;
        for (j = 0; j < effective_order; j++) {
            int idx = j * stride;
            sum += (int64_t)coeffs[idx] * decoded[j + (pred_order - effective_order)];
        }
        // Handle remaining elements if pred_order is not divisible by stride
        for (; j < pred_order; j++) {
            sum += (int64_t)coeffs[j] * decoded[pred_order - 1 - j];
        }
        decoded[pred_order] += sum >> qlevel;
    }
}
