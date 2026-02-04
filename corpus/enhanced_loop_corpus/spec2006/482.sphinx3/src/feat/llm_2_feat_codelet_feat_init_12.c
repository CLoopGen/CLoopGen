#include <stdio.h>

#include <inttypes.h>

typedef int int32;

extern char *type;
extern int32 i;
extern int32 l;
extern int32 k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (process every 2nd element)
    for (i = 1; i < l - 1; i += 2)
        if (type[i] == ',') {
            type[i] = ' ';
            k++;
        }
}
