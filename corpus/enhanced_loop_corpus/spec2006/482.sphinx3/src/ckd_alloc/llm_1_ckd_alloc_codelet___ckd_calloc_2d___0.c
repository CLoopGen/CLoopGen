#include <stdio.h>

#include <inttypes.h>

typedef int int32;

extern int32 d1;
extern int32 d2;
extern int32 elemsize;
extern char **ref;
extern char *mem;
extern int32 i;
extern int32 offset;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int32 j;
    for (i = 0; i < d1; i++) {
        offset = 0;
        for (j = 0; j < d2; j++) {
            offset += elemsize;
        }
        ref[i] = mem + i * offset;
    }
}
