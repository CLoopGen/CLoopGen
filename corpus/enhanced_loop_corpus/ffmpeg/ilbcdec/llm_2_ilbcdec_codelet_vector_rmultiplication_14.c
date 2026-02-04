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
    // Variant 1: Strided memory access with reverse traversal and stride of 2
    // Accesses every second element in 'in' and 'win', starting from opposite ends
    int stride = 2;
    int n = length - 1;
    for (int i = 0; i < length; i += stride) {
        out[i] = (in[i] * win[n - i]) >> shift;
        if (i + 1 < length) {
            out[i + 1] = (in[i + 1] * win[n - (i + 1)]) >> shift;
        }
    }
}
