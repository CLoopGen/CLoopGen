#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int width;
extern int i;
extern int16_t *b0;
extern int16_t *b1;
extern int16_t *b2;
extern int16_t *b3;
extern int16_t *b4;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int outer_i;
for (outer_i = 0; outer_i < width; outer_i += 8) {
    int limit = (outer_i + 8 < width) ? outer_i + 8 : width;
    for (i = outer_i; i < limit; i++) {
        b2[i] = (int)(((unsigned int)(b2[i]) - ((int)(9U * b1[i] + 9U * b3[i] - b4[i] - b0[i] + 16) >> 5)));
    }
}
}
