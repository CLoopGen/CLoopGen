#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int n;
extern int sixel_palet[1024];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 6; i++)
    for (int k = 0; k < 4; k++)
        sixel_palet[n++] = ((int)(((ssize_t)(((i * 4 + k) * 11) & 255) << 16) + ((((i * 4 + k) * 11) & 255) << 8) + (((i * 4 + k) * 11) & 255)));
}
