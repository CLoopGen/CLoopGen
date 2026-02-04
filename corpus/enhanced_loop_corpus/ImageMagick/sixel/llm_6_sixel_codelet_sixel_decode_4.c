#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int n;
extern int sixel_palet[1024];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp[24];
    for (i = 0; i < 24; i++) {
        temp[i] = (i * 11) & 255;
        sixel_palet[n + i] = ((int)(((ssize_t)temp[i] << 16) + (temp[i] << 8) + temp[i]));
    }
    n += 24;
}
