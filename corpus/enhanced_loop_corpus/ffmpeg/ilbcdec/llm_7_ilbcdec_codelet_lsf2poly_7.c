#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *a;
extern int32_t f[2][6];
extern int32_t tmp;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 5; i > 0; i--) {
        int idx_forward = 6 - i;
        int idx_backward = 5 + i;
        int32_t sum = f[0][idx_forward] + (unsigned int)f[1][idx_forward] + 4096;
        int32_t diff = f[0][idx_forward] - (unsigned int)f[1][idx_forward] + 4096;
        a[idx_forward] = sum >> 13;
        if (i < 5) {
            a[idx_backward + 1] = (sum >> 13); 
        }
        a[idx_backward] = diff >> 13;
    }
}
