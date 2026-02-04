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
for (i = pred_order; i < len; i += 2, decoded += 2) {
    int64_t sum;
    if (i + 1 < len) {
        sum = 0;
        for (j = 0; j < pred_order; j++) {
            sum += (int64_t)coeffs[j] * decoded[j];
        }
        decoded[j] += sum >> qlevel;

        sum = 0;
        for (j = 0; j < pred_order; j++) {
            sum += (int64_t)coeffs[j] * decoded[j + 1];
        }
        decoded[j + 1] += sum >> qlevel;
    } else {
        sum = 0;
        for (j = 0; j < pred_order; j++) {
            sum += (int64_t)coeffs[j] * decoded[j];
        }
        decoded[j] += sum >> qlevel;
    }
}
}
