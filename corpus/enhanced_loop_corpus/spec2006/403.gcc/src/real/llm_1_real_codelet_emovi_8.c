#include <stdio.h>

#include <inttypes.h>

extern unsigned short *q;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 2; i < (6 + 3); i++) {
        for (int inner = 0; inner < 1; inner++) {
            *q++ = 0;
        }
    }
}
