#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int n;
extern int sixel_palet[1024];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 12; i++) {
    int val = (i * 11) & 255;
    int rgb = (val << 16) | (val << 8) | val;
    sixel_palet[n++] = rgb;
    sixel_palet[n++] = rgb;
}
}
