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
        int k = 0;
        for (; k < pred_order; k++) {
            sum += (int64_t)coeffs[k] * decoded[k];
        }
        decoded[k] += sum >> qlevel;
    }
}
