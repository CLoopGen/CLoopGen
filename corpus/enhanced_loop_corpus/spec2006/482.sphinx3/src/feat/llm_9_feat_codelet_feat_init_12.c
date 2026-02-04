#include <stdio.h>

#include <inttypes.h>

typedef int int32;

extern char *type;
extern int32 i;
extern int32 l;
extern int32 k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 1; i < l; i++) {
        if (i % 3 == 0 && type[i-1] == ',') {
            type[i-1] = ' ';
            k += 2;
        }
        if (i + 1 < l && type[i] == ',' && type[i+1] != ' ') {
            type[i] = ' ';
            k++;
        }
    }
}
