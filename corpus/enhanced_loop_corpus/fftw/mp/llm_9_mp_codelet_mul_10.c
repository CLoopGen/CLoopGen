#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned short d[20];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 5; ++i) {
        d[4 * i] = d[4 * i + 1] = d[4 * i + 2] = d[4 * i + 3] = 0;
    }
}
