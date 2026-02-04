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
    IDWTELEM *b_ptr = b;
    IDWTELEM *temp_ptr = temp;
    for (x = 0; x < width2; x++) {
        *(temp_ptr + 2 * x) = *(b_ptr + x);
        *(temp_ptr + 2 * x + 1) = *(b_ptr + x + w2);
    }
}
