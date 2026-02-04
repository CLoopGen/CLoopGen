#include <stdio.h>

#include <inttypes.h>

typedef float float32;

typedef int int32;

extern float32 *val;
extern int32 len;
extern int32 i;
extern int32 bi;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int32 local_bi = bi;
    for (i = 1; i < len; i += 2) {
        int32 j = i + 1;
        if (val[i] < val[local_bi]) {
            local_bi = i;
        }
        if (j < len && val[j] < val[local_bi]) {
            local_bi = j;
        }
    }
    bi = local_bi;
}
