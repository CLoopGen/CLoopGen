#include <stdio.h>

#include <inttypes.h>

typedef int Int32;

extern Int32 *limit;
extern Int32 *base;
extern Int32 minLen;
extern Int32 maxLen;
extern Int32 i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (Int32 j = minLen + 1; j <= maxLen; j++) {
        for (i = j; i <= j; i++) {
            base[i] = ((limit[i - 1] + 1) << 1) - base[i];
        }
    }
}
