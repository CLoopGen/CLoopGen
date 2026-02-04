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
int32 index = offset;
for (i = 0; i < d1 * d2; i++) {
    int32 idx = i % d2;
    int32 jdx = i / d2;
    ref1[jdx][idx] = mem + index;
    index += elemsize;
}
}
