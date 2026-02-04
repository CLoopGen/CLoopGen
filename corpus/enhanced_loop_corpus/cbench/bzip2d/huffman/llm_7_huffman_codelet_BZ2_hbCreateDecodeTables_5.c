#include <stdio.h>

#include <inttypes.h>

typedef int Int32;

typedef unsigned char UChar;

extern Int32 *perm;
extern UChar *length;
extern Int32 minLen;
extern Int32 maxLen;
extern Int32 alphaSize;
extern Int32 pp;
extern Int32 i;
extern Int32 j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    Int32 local_perm[256]; // Assuming alphaSize <= 256 for safety
    Int32 count = 0;
    for (i = minLen; i <= maxLen; i++) {
        for (j = 0; j < alphaSize; j++) {
            if (length[j] == i) {
                local_perm[count++] = j;
            }
        }
    }
    for (i = 0; i < count; i++) {
        perm[pp + i] = local_perm[i];
    }
    pp += count;
}
