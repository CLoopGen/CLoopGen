#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int (*counttab2)[256];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 512; i += 2) {
        counttab2[i/2 + 1][i % 256] = 0;
        counttab2[i/2 + 1][(i + 1) % 256] = 0;
    }
}
