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
if (pred_order <= 0) return;
for (i = pred_order; i < len - 1; i++, decoded++) {
    int sum = 0;
    unsigned int c = coeffs[0];
    unsigned int d = decoded[0];
    for (j = 1; j < pred_order; j += 2) {
        sum += c * d;
        c = coeffs[j];
        d = decoded[j];
        if (j + 1 < pred_order) {
            sum += c * d;
            c = coeffs[j + 1];
            d = decoded[j + 1];
        }
    }
    if (j == pred_order) {
        sum += c * d;
        decoded[j] += (unsigned int)(sum >> qlevel);
    }
}
}
