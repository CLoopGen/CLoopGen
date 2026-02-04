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
    IDWTELEM temp_val;
    for (; (i & 30) != 30; i -= 2) {
        temp_val = temp[i >> 1];
        b[i + 1] = temp_val;
        b[i] = b[i >> 1];
    }
}
