#include <stdio.h>

#include <inttypes.h>

extern unsigned long *dst;
extern  unsigned long *src;
extern int top;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 1; i <= top; i++)
        dst[i-1] = src[i-1];
}
