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
    for (int outer = 0; outer < 1; outer++) {
        for (; (i & 62) != 62; i -= 2) {
            b[i + 1] = temp[i >> 1];
            b[i] = b[i >> 1];
        }
    }
}
