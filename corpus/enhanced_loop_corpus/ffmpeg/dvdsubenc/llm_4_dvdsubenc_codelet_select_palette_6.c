#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int out_palette[4];
extern int out_alpha[4];
extern int i;
extern int selected[4];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 4; i++) {
        int sel = selected[i];
        if (!sel) {
            out_palette[i] = 0;
            out_alpha[i] = 0;
            continue;
        }
        out_palette[i] = (sel - 1) & 15;
        out_alpha[i] = (sel < 17) ? 128 : 255;
    }
}
