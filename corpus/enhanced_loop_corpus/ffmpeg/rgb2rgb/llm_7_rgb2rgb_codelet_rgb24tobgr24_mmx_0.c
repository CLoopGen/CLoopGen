#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src;
extern uint8_t *dst;
extern int src_size;
extern unsigned int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    register uint8_t temp;
    for (i = 0; i < src_size; i += 3) {
        temp = src[i + 2];
        dst[i + 2] = src[i + 0];
        dst[i + 0] = temp;
        // Introduce artificial dependency: make dst[i+1] depend on prior iteration's temp
        if (i > 0) {
            dst[i + 1] = temp ^ dst[i - 1]; // WAR-like anti-dependence introduced via reuse of temp
        } else {
            dst[i + 1] = src[i + 1];
        }
    }
}
