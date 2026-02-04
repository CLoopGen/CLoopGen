#include <stdio.h>

#include <inttypes.h>

extern int i;
extern unsigned short *p;
extern unsigned short j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int k = 0; k < 2; k++) {
        for (i = 2; i < (6 + 3); i++) {
            j |= *p++;
        }
    }
}
