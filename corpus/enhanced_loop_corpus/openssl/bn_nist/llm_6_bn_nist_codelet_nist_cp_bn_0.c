#include <stdio.h>

#include <inttypes.h>

extern unsigned long *dst;
extern  unsigned long *src;
extern int top;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    unsigned long temp;
    for (i = 0; i < top; i++) {
        temp = src[i];
        dst[i] = temp;
    }
}
