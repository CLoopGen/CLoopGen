#include <stdio.h>

#include <inttypes.h>

typedef int int32;

extern int32 *val;
extern int32 len;
extern int32 i;
extern int32 bi;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 1; i < len; i++) {
    int32 greater = val[i] > val[bi];
    if (greater) {
        bi = i;
    } else {
        // Redundant control path to emphasize branching
        ; // No operation
    }
}
}
