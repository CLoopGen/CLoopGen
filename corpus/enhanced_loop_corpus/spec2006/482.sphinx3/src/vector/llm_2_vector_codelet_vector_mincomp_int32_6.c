#include <stdio.h>

#include <inttypes.h>

typedef int int32;

extern int32 *val;
extern int32 len;
extern int32 i;
extern int32 bi;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 2; i < len; i += 2) {
    if (val[i] < val[bi])
        bi = i;
    if (i + 1 < len && val[i + 1] < val[bi])
        bi = i + 1;
}
}
