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
    for (i = 1; i < n; i++) {
        out[i] = in1[i-1] ^ in2[i];
    }
    if (n > 0) {
        out[0] = in1[0] ^ in2[0];
    }
}
