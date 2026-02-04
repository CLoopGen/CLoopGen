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
for (i = minLen; i <= maxLen; i += 2) {
    vec += (base[i + 1] - base[i]);
    limit[i] = vec - 1;
    vec <<= 1;
    if (i + 1 <= maxLen) {
        vec += (base[i + 2] - base[i + 1]);
        limit[i + 1] = vec - 1;
        vec <<= 1;
    }
}
}
