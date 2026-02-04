#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

extern int32_t *out;
extern  int32_t *in;
extern integer len;
extern int i;
extern int64_t coeff;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < len; i++) {
        int64_t temp1 = coeff * in[i];
        int64_t temp2 = temp1 + 32768;
        int64_t temp3 = temp2 >> 15;
        out[i] = (int32_t)(temp3 < 2147483647 ? (temp3 > -2147483648 ? temp3 : -2147483648) : 2147483647);
    }
}
