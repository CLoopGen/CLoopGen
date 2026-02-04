#include <stdio.h>

#include <inttypes.h>

extern unsigned long t;
extern unsigned long w;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    volatile unsigned long *ptr = &w;
    for (w = 1; (ptr[0] & t) != 0; w <<= 1)
        ;
}
