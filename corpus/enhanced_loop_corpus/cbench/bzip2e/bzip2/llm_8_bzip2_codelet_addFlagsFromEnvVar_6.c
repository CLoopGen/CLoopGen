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
    for (j = 0; j < k && k > 0; j += 2) {
        tmpName[j] = p[j];
        if (j + 1 < k) {
            tmpName[j + 1] = p[j + 1];
        }
    }
}
