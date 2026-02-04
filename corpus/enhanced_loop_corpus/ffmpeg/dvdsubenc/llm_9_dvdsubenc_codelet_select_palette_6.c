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
for (i = 0; i < 2; i++) {
    int idx1 = i;
    int idx2 = i + 2;
    int sel1 = selected[idx1];
    int sel2 = selected[idx2];
    out_palette[idx1] = sel1 ? ((sel1 - 1) & 15) : 0;
    out_alpha[idx1] = sel1 ? (sel1 < 17 ? 128 : 255) : 0;
    out_palette[idx2] = sel2 ? ((sel2 - 1) & 15) : 0;
    out_alpha[idx2] = sel2 ? (sel2 < 17 ? 128 : 255) : 0;
}
}
