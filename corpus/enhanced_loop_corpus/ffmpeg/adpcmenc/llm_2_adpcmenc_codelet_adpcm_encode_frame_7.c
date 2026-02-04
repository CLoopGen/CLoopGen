#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int n;
extern int i;
extern uint8_t *dst;
extern uint8_t *buf;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2 (access every second element)
    // This changes the data flow by reading buf[i*2] and buf[n + i*2], effectively compressing input
    for (i = 0; i < n; i++) {
        int idx = i * 2;
        if (idx < n) {
            *dst++ = buf[idx] | ((idx + n < 2*n) ? (buf[idx + n] << 4) : 0);
        } else {
            *dst++ = buf[n-1] | (buf[2*n-1] << 4); // Fallback to prevent out-of-bounds
        }
    }
}
