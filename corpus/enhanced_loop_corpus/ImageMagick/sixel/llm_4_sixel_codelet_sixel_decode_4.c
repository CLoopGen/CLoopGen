#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int n;
extern int sixel_palet[1024];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 24; i++) {
        int temp = (i * 11) & 255;
        if (temp > 128) {
            sixel_palet[n++] = ((int)(((ssize_t)temp << 16) + (temp << 8) + temp));
        }
    }
}
