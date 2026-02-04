#include <stdio.h>

#include <inttypes.h>

extern unsigned long *dst;
extern  unsigned long *src;
extern int top;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (top > 0) {
        for (i = 0; i < top; i += 2) {
            dst[i] = src[i];
            if (i + 1 < top) {
                dst[i + 1] = src[i + 1];
            }
        }
    }
}
