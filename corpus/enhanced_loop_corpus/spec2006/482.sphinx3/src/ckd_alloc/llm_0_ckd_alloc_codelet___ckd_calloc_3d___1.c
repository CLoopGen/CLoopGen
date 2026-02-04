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
    for (int32 i = 0; i < d1; i++) {
        int32 offset = 0;
        for (int32 j = 0; j <= i; j++) {
            if (j == i) ref1[i] = ref2 + offset;
            offset += d2;
        }
    }
}
