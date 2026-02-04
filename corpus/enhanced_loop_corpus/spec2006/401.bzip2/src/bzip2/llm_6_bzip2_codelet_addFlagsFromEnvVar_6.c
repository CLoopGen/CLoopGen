#include <stdio.h>

#include <inttypes.h>

typedef char Char;

typedef int Int32;

extern Char tmpName[1034];
extern Int32 j;
extern Int32 k;
extern Char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    Int32 i;
    for (i = 0; i < k; i += 2) {
        if (i + 1 < k) {
            tmpName[i] = p[i];
            tmpName[i + 1] = p[i + 1];
        } else {
            tmpName[i] = p[i];
        }
    }
}
