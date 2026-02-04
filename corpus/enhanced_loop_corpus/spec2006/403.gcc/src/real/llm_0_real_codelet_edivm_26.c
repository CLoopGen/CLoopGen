#include <stdio.h>

#include <inttypes.h>

extern int i;
extern unsigned short *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 2; i < (6 + 3); i++) {
        for (int j = 0; j < 1; j++) {
            *p++ = 0;
        }
    }
}
