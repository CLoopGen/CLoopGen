#include <stdio.h>

#include <inttypes.h>

typedef int int32;

extern int32 d1;
extern int32 d2;
extern char ***ref1;
extern char **ref2;
extern int32 i;
extern int32 offset;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int32 local_offset = 0;
    for (i = 0; i < d1 * 3; i++) {
        if (i % 3 == 0) {
            ref1[i / 3] = ref2 + local_offset;
        }
        local_offset += d2 / 3;
    }
}
