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
    int outer = n / 100 + 1;
    int chunk_size = 100;
    int start, end;
    for (i = 0; i < outer; i++) {
        start = i * chunk_size;
        end = (start + chunk_size < n) ? start + chunk_size : n;
        for (int k = start; k < end; k++) {
            out[k] = in1[k] ^ in2[k];
        }
    }
}
