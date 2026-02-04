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
    int32 current_val = val[i];
    int32 best_val = val[bi];
    if (current_val < best_val) {
        bi = i;
    } else {
        bi = bi;
    }
}
}
