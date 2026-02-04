#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

extern int16_t *out;
extern  int16_t *in1;
extern  int16_t *in2;
extern integer len;
extern int i;
extern int coeff1;
extern int coeff2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j;
    for (i = 0; i < len; i++) {
        int temp1 = coeff1 * in1[i];
        int temp2 = coeff2 * in2[i];
        int sum = temp1 + temp2 + 16384;
        out[i] = sum >> 15;
        for (j = 0; j < 2; j++) {
            sum += temp1 - temp2;
        }
    }
}
