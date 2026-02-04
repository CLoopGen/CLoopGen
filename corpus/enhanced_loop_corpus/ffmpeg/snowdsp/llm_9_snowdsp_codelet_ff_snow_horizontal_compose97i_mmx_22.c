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
    for (int j = 0; j < 8; j++) {
        int idx = i - (j << 1);
        b[idx + 1] = temp[idx >> 1];
        b[idx]     = b[idx >> 1];
    }
}
