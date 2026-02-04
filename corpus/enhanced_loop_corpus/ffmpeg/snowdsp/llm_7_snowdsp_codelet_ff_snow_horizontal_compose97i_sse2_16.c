#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef short IDWTELEM;

extern IDWTELEM *b;
extern IDWTELEM *temp;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    IDWTELEM *b_local = b;
    IDWTELEM *temp_local = temp;
    int i_local = i;
    for (; (i_local & 62) != 62; i_local -= 2) {
        b_local[i_local + 1] = temp_local[i_local >> 1];
        b_local[i_local] = b_local[i_local >> 1];
    }
    i = i_local;
}
