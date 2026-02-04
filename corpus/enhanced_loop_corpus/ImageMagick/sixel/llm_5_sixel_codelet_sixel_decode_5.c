#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int n;
extern int sixel_palet[1024];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int val = ((int)(((ssize_t)((255) & 255) << 16) + (((255) & 255) << 8) + ((255) & 255)));
    for (; n < 1024; n += 4) {
        sixel_palet[n] = val;
        if (n + 1 < 1024) sixel_palet[n + 1] = val;
        if (n + 2 < 1024) sixel_palet[n + 2] = val;
        if (n + 3 < 1024) sixel_palet[n + 3] = val;
    }
}
