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
    int temp_result;
    for (j = 0; j < pred_order; j++) {
        sum += (int64_t)coeffs[j] * decoded[j];
    }
    temp_result = (int)(sum >> qlevel);
    decoded[pred_order] = temp_result;
}
}
