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
for (i = 1; i < len; i += 2) {
    if (i + 1 < len) {
        int32 temp_bi1 = val[i] < val[bi] ? i : bi;
        int32 temp_bi2 = val[i+1] < val[bi] ? i+1 : bi;
        bi = val[temp_bi1] < val[temp_bi2] ? temp_bi1 : temp_bi2;
    } else {
        if (val[i] < val[bi])
            bi = i;
    }
}
}
