#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int n;
extern int sixel_palet[1024];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int j;
for (i = 0; i < 24; i++)
    for (j = 0; j < 1; j++)
        sixel_palet[n++] = ((int)(((ssize_t)((i * 11) & 255) << 16) + (((i * 11) & 255) << 8) + ((i * 11) & 255)));
}
