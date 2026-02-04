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
int temp_palette[4] = {0};
int temp_alpha[4] = {0};
for (i = 0; i < 4; i += 1) {
    int sel = selected[i];
    int not_sel = !sel;
    int lt_17 = sel < 17;
    temp_palette[i] = not_sel ? 0 : (sel - 1) & 15;
    temp_alpha[i] = not_sel ? 0 : (lt_17 ? 128 : 255);
}
for (i = 0; i < 4; i++) {
    out_palette[i] = temp_palette[i];
    out_alpha[i] = temp_alpha[i];
}
}
