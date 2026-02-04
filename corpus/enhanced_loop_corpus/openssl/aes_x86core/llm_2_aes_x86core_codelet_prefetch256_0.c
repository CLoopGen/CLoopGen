#include <stdio.h>

#include <inttypes.h>

extern volatile unsigned long *t;
extern unsigned long sum;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    sum = 0;
    for (i = 0; i < 256 / sizeof(t[0]); i++) {
        sum ^= t[i];
    }
}
