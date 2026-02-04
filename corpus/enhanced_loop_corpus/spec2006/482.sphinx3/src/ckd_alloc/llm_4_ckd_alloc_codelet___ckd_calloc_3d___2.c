#include <stdio.h>

#include <inttypes.h>

typedef int int32;

extern int32 d1;
extern int32 d2;
extern int32 d3;
extern int32 elemsize;
extern char ***ref1;
extern char *mem;
extern int32 i;
extern int32 j;
extern int32 offset;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < d1; i++) {
        if (i % 2 == 0) {
            for (j = 0; j < d2; j++) {
                ref1[i][j] = mem + offset;
                offset += d3 * elemsize;
            }
        } else {
            continue;
        }
    }
}
