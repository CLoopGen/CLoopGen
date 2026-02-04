#include <stdio.h>

#include <inttypes.h>

typedef int int32;

extern int32 *val;
extern int32 len;
extern int32 i;
extern int32 bi;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int32 indices[2] = {i, i + 1};
for (i = 1; i < len - 1; i++) {
    indices[0] = i;
    indices[1] = i + 1;
    if (val[indices[0]] < val[bi])
        bi = indices[0];
    if (val[indices[1]] < val[bi])
        bi = indices[1];
}
if (i < len && val[i] < val[bi])
    bi = i;
}
