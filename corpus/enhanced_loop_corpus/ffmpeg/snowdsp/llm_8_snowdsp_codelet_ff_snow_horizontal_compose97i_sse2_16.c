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
    for (; (i & 62) != 62; i -= 4) {
        b[i + 3] = temp[(i + 2) >> 1];
        b[i + 2] = temp[i >> 1];
        b[i + 1] = b[(i + 2) >> 1];
        b[i] = b[i >> 1];
        if ((i & 62) == 62) break;
    }
}
