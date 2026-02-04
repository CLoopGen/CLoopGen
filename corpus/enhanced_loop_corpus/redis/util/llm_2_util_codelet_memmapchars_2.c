#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern char *s;
extern size_t len;
extern  char *from;
extern  char *to;
extern size_t setlen;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2, unrolled to process two elements per iteration
    size_t j = 0;
    for (; j + 1 < len; j += 2) {
        for (size_t i = 0; i < setlen; i++) {
            if (s[j] == from[i]) {
                s[j] = to[i];
                break;
            }
        }
        for (size_t i = 0; i < setlen; i++) {
            if (s[j+1] == from[i]) {
                s[j+1] = to[i];
                break;
            }
        }
    }
    // Handle remaining element if length is odd
    if (j < len) {
        for (size_t i = 0; i < setlen; i++) {
            if (s[j] == from[i]) {
                s[j] = to[i];
                break;
            }
        }
    }
}
