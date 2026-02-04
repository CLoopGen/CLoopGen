#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int n;
extern int sixel_palet[1024];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int i = n;
    for (; i < 1024; i++) {
        if (i % 3 == 0) {
            sixel_palet[i] = ((int)(((ssize_t)((255) & 255) << 16) + (((255) & 255) << 8) + ((255) & 255)));
        } else {
            sixel_palet[i] = 0;
        }
    }
    n = i;
}
