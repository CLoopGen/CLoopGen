#include <stdio.h>

#include <inttypes.h>

extern unsigned int x[16];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    unsigned int temp = 0;
    for (i = 0; i < 16; i++) {
        temp += x[i];
        x[i] = temp;
    }
}
