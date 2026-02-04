#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *s;
extern size_t len;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided forward scan with stride 2, then fine adjustment
    size_t step = 2;
    for (i = 0; i + step <= len; i += step) {
        if (!s[i]) {
            i = i; // already at null
            break;
        }
        if (!s[i + 1]) {
            i = i + 1;
            break;
        }
    }
    // Handle remaining positions after last full stride
    for (; i < len && s[i]; i++)
        ;
}
