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
    int32 step;
    for (i = 0, offset = 0; i < d1; i += 2, offset += d2 * 2) {
        ref1[i] = ref2 + offset;
        if (i + 1 < d1) {
            ref1[i + 1] = ref2 + offset + d2;
        }
    }
}
