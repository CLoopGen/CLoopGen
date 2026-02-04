#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef short IDWTELEM;

extern IDWTELEM *b0;
extern IDWTELEM *b1;
extern IDWTELEM *b2;
extern IDWTELEM *b3;
extern IDWTELEM *b4;
extern IDWTELEM *b5;
extern int width;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    IDWTELEM temp_b3, temp_b2;
    for (i = 0; i < width; i++) {
        // Introduce temporary variables to break WAW and WAR dependencies
        // and reorganize computation order to modify data flow.
        temp_b3 = b3[i] - (1 * (b2[i] + b4[i]) + 0) >> 0;
        b4[i] = b4[i] - (3 * (b3[i] + b5[i]) + 4) >> 3;
        temp_b2 = b2[i] + (1 * (b1[i] + temp_b3) + 4 * b2[i] + 8) >> 4;
        b1[i] = b1[i] + (3 * (b0[i] + temp_b2) + 0) >> 1;
        b2[i] = temp_b2;
        b3[i] = temp_b3;
    }
}
