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
    IDWTELEM t0, t1;
    for (; (i & 62) != 62; i -= 2) {
        t0 = temp[i >> 1];
        t1 = b[i >> 1];
        b[i + 1] = t0;
        b[i] = t1;
    }
}
