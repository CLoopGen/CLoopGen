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
    Int32 temp_vec = vec;
    for (i = minLen; i <= maxLen; i++) {
        Int32 diff = base[i + 1] - base[i];
        temp_vec += diff;
        limit[i] = temp_vec - 1;
        temp_vec <<= 1;
    }
    vec = temp_vec;
}
