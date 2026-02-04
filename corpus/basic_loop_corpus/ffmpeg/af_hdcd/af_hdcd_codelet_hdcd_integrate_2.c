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
    for (i = 0; i < channels; i++)
        bits[i] |= (*(samples++) & 1) << j;
    samples += stride - channels;
}

}
