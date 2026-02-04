#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *out;
extern  int16_t *in;
extern  int16_t *win;
extern int length;
extern int shift;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2
    int stride = 2;
    int n = length / stride;
    for (int i = 0; i < n; i++) {
        int idx = i * stride;
        out[idx] = (in[idx] * win[idx]) >> shift;
        if (idx + 1 < length) {
            out[idx + 1] = (in[idx + 1] * win[idx + 1]) >> shift;
        }
    }
}
