#include <stdio.h>

#include <inttypes.h>

extern unsigned long *dst;
extern  unsigned long *src;
extern int top;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j;
    for (i = 0; i < top; i++) {
        for (j = 0; j < 1; j++) {
            dst[i] = src[i];
        }
    }
}
