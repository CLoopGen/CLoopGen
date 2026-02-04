#include <stdio.h>

#include <inttypes.h>

extern unsigned short c[];
extern unsigned short p[9];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 2; i < (6 + 3); i++) {
        for (int k = 0; k < 1; k++)
            c[i] = p[i];
    }
}
