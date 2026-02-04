#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern void *B;
extern  int ldb;
extern int i;
extern int j;
extern int n1;
extern int n2;
extern  float alpha_real;
extern  float alpha_imag;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with a fixed stride over flattened index space
    const ptrdiff_t total_elements = n1 * n2;
    const ptrdiff_t stride = 4;  // Process every 4th complex element (8 floats) for strided pattern
    for (ptrdiff_t s = 0; s < stride; s++) {
        for (ptrdiff_t k = s; k < total_elements; k += stride) {
            const int i = k / n2;
            const int j = k % n2;
            if (i >= n1) continue;
            const ptrdiff_t base_offset = 2 * (ldb * i + j);
            const float Bij_real = ((float *)B)[base_offset];
            const float Bij_imag = ((float *)B)[base_offset + 1];
            ((float *)B)[base_offset]     = alpha_real * Bij_real - alpha_imag * Bij_imag;
            ((float *)B)[base_offset + 1] = alpha_real * Bij_imag + alpha_imag * Bij_real;
        }
    }
}
