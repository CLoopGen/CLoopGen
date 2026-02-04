#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int (*counttab2)[256];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp[256];
    for (i = 0; i < 256; i++) {
        temp[i] = i * 2;
        counttab2[i + 1][i] = temp[i];
    }
    for (i = 0; i < 256; i++) {
        counttab2[i][255 - i] += temp[i];
    }
}
