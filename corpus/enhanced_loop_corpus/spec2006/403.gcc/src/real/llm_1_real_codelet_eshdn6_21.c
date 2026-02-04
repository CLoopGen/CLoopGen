#include <stdio.h>

#include <inttypes.h>

extern unsigned short *x;
extern int i;
extern unsigned short *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 2; i < (6 + 3) - 1; i++) {
        for (int inner = 0; inner < 1; inner++) {
            *(--p) = *(--x);
        }
    }
}
