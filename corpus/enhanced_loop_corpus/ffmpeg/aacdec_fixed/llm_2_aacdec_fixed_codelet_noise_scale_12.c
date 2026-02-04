#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int *coefs;
extern int len;
extern int s;
extern int i;
extern int c;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (access every 2nd element forward, then second pass for odd indices)
    int stride = 2;
    for (i = 0; i < len; i += stride) {
        if (i < len) {
            coefs[i] = -(int64_t)coefs[i] * c * (1 << -s);
        }
        int next = i + 1;
        if (next < len) {
            coefs[next] = -(int64_t)coefs[next] * c * (1 << -s);
        }
    }
}
