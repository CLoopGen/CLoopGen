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
for (i = 0 , offset = 0; i < d1; i++ , offset += d2 * elemsize) {
    if (d2 <= 0) {
        continue;
    }
    ref[i] = mem + offset;
}
}
