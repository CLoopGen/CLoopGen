#include <stdio.h>

#include <inttypes.h>

typedef int Int32;

extern Int32 *limit;
extern Int32 *base;
extern Int32 minLen;
extern Int32 maxLen;
extern Int32 i;
extern Int32 vec;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = minLen; i <= maxLen; i++) {
    for (Int32 j = 0; j < 2; j++) {
        vec += (base[i + 1] - base[i]);
        limit[i] = vec - 1;
        vec <<= 1;
    }
}
}
