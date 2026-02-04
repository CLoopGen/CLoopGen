#include <stdio.h>

#include <inttypes.h>

typedef int int32;

extern int32 *val;
extern int32 len;
extern int32 i;
extern int32 bi;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int32 j;
for (i = 1; i < len && bi < len - 1; i++) {
    for (j = 1; j < len - i; j++) {
        if (val[bi + j] > val[bi])
            bi = bi + j;
    }
}
}
