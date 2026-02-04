#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int n;
extern int sixel_palet[1024];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 48; i += 2)
    sixel_palet[n++] = ((int)(((ssize_t)((i * 5 + 3) & 255) << 16) + (((i * 5 + 3) & 255) << 8) + ((i * 5 + 3) & 255)));
}
