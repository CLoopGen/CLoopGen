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
    int temp_palette[4];
    int temp_alpha[4];
    for (i = 0; i < 4; i++) {
        temp_palette[i] = selected[i] ? (selected[i] - 1) & 15 : 0;
        temp_alpha[i] = !selected[i] ? 0 : selected[i] < 17 ? 128 : 255;
    }
    for (i = 0; i < 4; i++) {
        out_palette[i] = temp_palette[i];
        out_alpha[i] = temp_alpha[i];
    }
}
