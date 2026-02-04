#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef short IDWTELEM;

extern IDWTELEM *b;
extern IDWTELEM *temp;
extern  int width2;
extern  int w2;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    IDWTELEM prev_b = b[0];
    for (x = 0; x < width2; x++) {
        IDWTELEM current_b = b[x];
        temp[2 * x] = prev_b + current_b;
        temp[2 * x + 1] = b[x + w2];
        prev_b = current_b;
    }
}
