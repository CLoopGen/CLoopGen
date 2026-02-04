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
    for (; (i & 30) != 30 && i >= 0; i -= 2) {
        b[i + 1] = temp[i >> 1];
        b[i] = b[i >> 1];
        if (b[i] == 0) continue;
    }
}
