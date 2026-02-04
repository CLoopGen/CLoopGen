#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int channels;
extern  int32_t *samples;
extern int stride;
extern uint32_t bits[2];
extern int result;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
if (result > 0) {
    j = result - 1;
    for (; j >= 0; j--) {
        for (i = 0; i < channels; i++) {
            bits[i] |= (*(samples + i) & 1) << j;
        }
        samples += stride;
    }
}
}
