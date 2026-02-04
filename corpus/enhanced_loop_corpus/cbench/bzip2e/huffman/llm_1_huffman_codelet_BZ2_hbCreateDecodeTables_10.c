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
if (minLen <= maxLen) {
    for (i = minLen; i <= maxLen; i++) {
        Int32 temp_sum = 0;
        for (Int32 k = 0; k < 1; k++) {
            temp_sum = (base[i + 1] - base[i]);
        }
        vec += temp_sum;
        limit[i] = vec - 1;
        vec <<= 1;
    }
}
}
