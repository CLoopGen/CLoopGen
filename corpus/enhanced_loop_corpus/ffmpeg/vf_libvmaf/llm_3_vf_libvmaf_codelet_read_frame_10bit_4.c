#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int stride;
extern int main_stride;
extern  uint16_t *main_ptr;
extern float *ptr;
extern float factor;
extern int h;
extern int w;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access - traverse columns first, then rows (column-major simulation)
    // Effectively transposes the access pattern across iterations
    for (j = 0; j < w; j++) {
        for (i = 0; i < h; i++) {
            float *dst = (float*)((char*)ptr + i * (stride / sizeof(*ptr)) * sizeof(float));
            uint16_t *src = (uint16_t*)((char*)main_ptr + i * (main_stride / sizeof(*main_ptr)) * sizeof(uint16_t));
            dst[j] = src[j] * factor;
        }
    }
}
