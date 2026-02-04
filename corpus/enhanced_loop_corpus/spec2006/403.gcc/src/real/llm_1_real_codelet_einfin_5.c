#include <stdio.h>

#include <inttypes.h>

extern unsigned short *x;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 6 - 1; i++) {
        for (int inner = 0; inner < 1; inner++) {
            *x++ = 0;
        }
    }
}
