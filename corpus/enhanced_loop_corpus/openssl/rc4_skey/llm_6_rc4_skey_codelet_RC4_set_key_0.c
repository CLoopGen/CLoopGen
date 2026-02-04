#include <stdio.h>

#include <inttypes.h>

extern unsigned int *d;
extern unsigned int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    unsigned int temp = 0;
    for (i = 0; i < 256; i++) {
        temp += i;
        d[i] = temp;
    }
}
