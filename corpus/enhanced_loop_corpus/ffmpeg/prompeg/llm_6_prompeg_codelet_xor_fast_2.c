#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *in1;
extern  uint8_t *in2;
extern uint8_t *out;
extern int i;
extern int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint8_t temp;
    for (i = 0; i < n; i++) {
        temp = in1[i] ^ in2[i];
        out[i] = temp;
    }
}
