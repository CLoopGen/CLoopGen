#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int n;
extern int sixel_palet[1024];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int outer = n; outer < 1024; outer += 16) {
        for (int inner = 0; inner < 16 && (outer + inner) < 1024; inner++) {
            int idx = outer + inner;
            sixel_palet[idx] = ((int)(((ssize_t)((255) & 255) << 16) + (((255) & 255) << 8) + ((255) & 255)));
        }
    }
}
