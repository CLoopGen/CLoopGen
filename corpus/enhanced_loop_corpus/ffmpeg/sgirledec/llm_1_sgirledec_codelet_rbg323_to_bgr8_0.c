#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern  uint8_t *src;
extern int size;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (size > 0) {
        int chunk = 1;
        for (i = 0; i < size; i += chunk) {
            int end = i + chunk;
            if (end > size) end = size;
            for (int k = i; k < end; k++) {
                dst[k] = ((((src[k]) << 3) & 192) | (((src[k]) << 3) & 56) | (((src[k]) >> 5) & 7));
            }
        }
    }
}
