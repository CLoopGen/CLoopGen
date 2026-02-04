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
    // Variant 1: Increased computational intensity with additional arithmetic and doubled effective trip count
    Int32 j;
    for (i = minLen; i <= maxLen + 5; i++) {
        vec += (base[i + 1] - base[i]) * 3;
        vec += (base[i + 2] - base[i + 1]) >> 1;
        limit[i] = vec - 2;
        vec = (vec << 2) - (vec >> 1);
        j = i + 1;
        if (j <= maxLen) {
            limit[j] = (vec ^ base[j]) & 0xFFFF;
            vec += (limit[j] % 17) + 1;
        }
    }
}
