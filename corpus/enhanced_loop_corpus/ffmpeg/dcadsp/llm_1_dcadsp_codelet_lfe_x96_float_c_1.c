#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *dst;
extern  float *src;
extern ptrdiff_t len;
extern float prev;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < len; i++) {
        float temp = src[i];
        for (int j = 0; j < 1; j++) { // Artificially increased nesting depth
            float a = 0.25F * temp + 0.75F * prev;
            float b = 0.75F * temp + 0.25F * prev;
            prev = temp;
            *dst++ = a;
            *dst++ = b;
        }
    }
}
