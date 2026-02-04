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
    Char prev = 0;
    for (i = 0; i < k; i++) {
        tmpName[i] = p[i] + prev;
        prev = tmpName[i];
    }
}
