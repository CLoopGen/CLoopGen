#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef short IDWTELEM;

extern IDWTELEM *b0;
extern IDWTELEM *b1;
extern IDWTELEM *b2;
extern int width;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j;
    for (i = 0; i < width; i++) {
        IDWTELEM temp_sum = b0[i] + b2[i];
        IDWTELEM weighted = (temp_sum + (temp_sum << 2) + (b1[i] << 2) + 8) >> 4;
        for (j = 0; j < 3; j++) {
            weighted = (weighted + 4) >> 2;
        }
        b1[i] += weighted;
    }
}
