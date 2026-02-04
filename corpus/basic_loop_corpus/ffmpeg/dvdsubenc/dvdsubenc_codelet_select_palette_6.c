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
    out_palette[i] = selected[i] ? (selected[i] - 1) & 15 : 0;
    out_alpha[i] = !selected[i] ? 0 : selected[i] < 17 ? 128 : 255;
}

}
