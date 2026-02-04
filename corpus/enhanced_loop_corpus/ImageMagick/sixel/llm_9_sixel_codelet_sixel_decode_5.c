#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int n;
extern int sixel_palet[1024];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int i;
    for (i = n; i < 1024; i++) {
        int r = (i * 7) & 255;
        int g = (i * 13) & 255;
        int b = (i * 19) & 255;
        ssize_t packed = ((ssize_t)r << 16) | (g << 8) | b;
        sixel_palet[i] = (int)packed;
    }
    n = i;
}
