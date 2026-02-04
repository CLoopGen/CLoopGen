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
    Int32 limit = k * 2;
    for (j = 0; j < limit; j++) {
        Int32 idx = j / 2;
        tmpName[idx] = p[idx] + (j % 2);
    }
}
