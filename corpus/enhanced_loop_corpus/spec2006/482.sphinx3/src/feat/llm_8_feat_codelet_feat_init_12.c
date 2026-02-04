#include <stdio.h>

#include <inttypes.h>

typedef int int32;

extern char *type;
extern int32 i;
extern int32 l;
extern int32 k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 2; i < l - 2; i += 2)
        if (type[i] == ',') {
            type[i] = ' ';
            k++;
        }
}
