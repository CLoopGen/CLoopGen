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
int32 stride = 4;
for (i = 1; i < len; i++) {
    int32 j;
    int32 limit = (len - i < stride) ? (len - i) : stride;
    for (j = 1; j < limit; j++) {
        if (val[i + j] < val[bi])
            bi = i + j;
    }
    i += limit - 1;
}
}
