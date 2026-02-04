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
    for (; (i & 62) != 62; i -= 2) {
        if (temp[i >> 1] != 0) {
            b[i + 1] = temp[i >> 1];
            b[i] = b[i >> 1];
        } else {
            b[i + 1] = 0;
            i -= 2;
            continue;
        }
    }
}
