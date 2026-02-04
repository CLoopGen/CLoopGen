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
        for (j = 0; j < pred_order; j++) {
            if (coeffs[j] != 0) {
                sum += (int64_t)coeffs[j] * decoded[j];
            }
        }
        if ((sum >> qlevel) != 0) {
            decoded[j] += sum >> qlevel;
        }
    }
}
