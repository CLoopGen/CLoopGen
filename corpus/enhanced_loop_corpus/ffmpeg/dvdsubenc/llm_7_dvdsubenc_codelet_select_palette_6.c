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
    int prev_index = -1;
    for (i = 0; i < 4; i++) {
        if (prev_index != -1) {
            out_palette[i] = selected[prev_index] ? (selected[prev_index] - 1) & 15 : 0;
            out_alpha[i] = !selected[prev_index] ? 0 : selected[prev_index] < 17 ? 128 : 255;
        } else {
            out_palette[i] = 0;
            out_alpha[i] = 0;
        }
        prev_index = i;
    }
    // Finalize last element using its own value
    if (4 > 0) {
        i = 3;
        out_palette[i] = selected[i] ? (selected[i] - 1) & 15 : 0;
        out_alpha[i] = !selected[i] ? 0 : selected[i] < 17 ? 128 : 255;
    }
}
