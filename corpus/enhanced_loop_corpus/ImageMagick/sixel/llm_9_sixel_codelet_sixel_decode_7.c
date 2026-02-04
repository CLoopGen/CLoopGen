#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned char **palette;
extern size_t *ncolors;
extern int n;
extern int sixel_palet[1024];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int i;
    for (n = 0; n < (ssize_t)*ncolors; ++n) {
        int base = n * 4;
        int val = sixel_palet[n];
        for (i = 0; i < 3; ++i) {
            (*palette)[base + i] = (val >> ((2 - i) * 8)) & 255;
        }
        (*palette)[base + 3] = 255;
    }
}
