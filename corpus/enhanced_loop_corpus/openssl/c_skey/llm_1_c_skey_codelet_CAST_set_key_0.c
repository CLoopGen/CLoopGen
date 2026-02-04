#include <stdio.h>

#include <inttypes.h>

extern unsigned int x[16];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 4; i++) {
        x[i * 4 + 0] = 0;
        x[i * 4 + 1] = 0;
        x[i * 4 + 2] = 0;
        x[i * 4 + 3] = 0;
    }
}
