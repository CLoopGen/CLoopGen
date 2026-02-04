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
    Int32 prev_limit_shifted;
    for (i = minLen + 1; i <= maxLen; i++) {
        prev_limit_shifted = (limit[i - 1] + 1) << 1;
        base[i] = prev_limit_shifted - base[i];
        limit[i - 1] = base[i]; // Introduces WAW and WAR dependency by writing to limit
    }
}
