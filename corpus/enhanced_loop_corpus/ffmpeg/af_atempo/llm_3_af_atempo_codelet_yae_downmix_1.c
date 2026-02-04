#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float FFTSample;

extern  uint8_t *src;
extern  uint8_t *src_end;
extern FFTSample *xdat;
extern uint8_t tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint8_t **indirect_src = (uint8_t**)malloc((src_end - src) * sizeof(uint8_t*));
    if (!indirect_src) return;
    for (int i = 0; &src[i] < src_end; i++) {
        indirect_src[i] = &src[i];
    }
    size_t count = src_end - src;
    for (size_t i = 0; i < count; i++, xdat++) {
        tmp = *(const uint8_t *)indirect_src[i];
        *xdat = (FFTSample)tmp;
    }
    free(indirect_src);
}
