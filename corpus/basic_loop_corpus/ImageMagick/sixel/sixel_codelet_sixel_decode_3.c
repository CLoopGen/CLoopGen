#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int b;
extern int g;
extern int n;
extern int r;
extern int sixel_palet[1024];

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (r = 0; r < 6; r++) {
    for (g = 0; g < 6; g++) {
        for (b = 0; b < 6; b++) {
            sixel_palet[n++] = ((int)(((ssize_t)((r * 51) & 255) << 16) + (((g * 51) & 255) << 8) + ((b * 51) & 255)));
        }
    }
}

}
