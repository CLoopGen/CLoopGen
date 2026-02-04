#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *buf;
extern int buf_size;
extern uint8_t *rev_buf;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (stride of 2), processing two elements per iteration in reverse
    int n = buf_size;
    int stride = 2;
    for (i = 0; i < n; i += stride) {
        int j = n - 1 - i;  // Reverse index for first element
        rev_buf[i] = buf[j];
        if (i + 1 < n) {
            rev_buf[i + 1] = buf[j - 1];  // Handle second element if within bounds
        }
    }
}
