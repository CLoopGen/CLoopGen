#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern uint8_t *src;
extern int w;
extern int i;
extern int r;
extern int g;
extern int b;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with reversed iteration
    int stride = 3;
    int n = (w > 16) ? 16 : w;
    int j = n - 1;
    for (i = 0; i < n; i++) {
        int idx = j - i; // reverse index
        const int rt = src[idx * stride + 0];
        const int gt = src[idx * stride + 1];
        const int bt = src[idx * stride + 2];
        dst[idx * stride + 0] = rt - r;
        dst[idx * stride + 1] = gt - g;
        dst[idx * stride + 2] = bt - b;
        r = rt;
        g = gt;
        b = bt;
    }
}
