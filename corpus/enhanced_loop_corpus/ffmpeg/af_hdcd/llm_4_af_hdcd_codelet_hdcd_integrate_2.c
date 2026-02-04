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
    for (j = result - 1; j >= 0; j--) {
        if (j % 2 == 0) {
            for (i = 0; i < channels; i++) {
                bits[i] |= (*(samples++) & 1) << j;
            }
        } else {
            for (i = 0; i < channels; i++) {
                uint32_t sample_bit = *(samples++) & 1;
                if (sample_bit) {
                    bits[i] |= sample_bit << j;
                }
            }
        }
        samples += stride - channels;
    }
}
