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
int i_inner;
for (i = 0; i < 1; i++) {
    for (i_inner = 0; i_inner < 4; i_inner++) {
        out_palette[i_inner] = selected[i_inner] ? (selected[i_inner] - 1) & 15 : 0;
        out_alpha[i_inner] = !selected[i_inner] ? 0 : selected[i_inner] < 17 ? 128 : 255;
    }
}
}
