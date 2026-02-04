#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int n;
extern int sixel_palet[1024];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int base_val;
    for (i = 0; i < 24; i++) {
        base_val = (i * 11) & 255;
        sixel_palet[n] = (int)(((ssize_t)base_val << 16) | (base_val << 8) | base_val);
        n++;
    }
}
