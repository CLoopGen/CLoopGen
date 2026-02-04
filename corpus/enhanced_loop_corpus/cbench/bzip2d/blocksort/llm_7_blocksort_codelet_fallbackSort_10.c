#include <stdio.h>

#include <inttypes.h>

typedef unsigned int UInt32;

typedef int Int32;

typedef unsigned char UChar;

extern UInt32 *fmap;
extern Int32 nblock;
extern Int32 ftabCopy[256];
extern Int32 i;
extern Int32 j;
extern UChar *eclass8;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    Int32 local_ftabCopy[256];
    for (i = 0; i < 256; i++) {
        local_ftabCopy[i] = ftabCopy[i];
    }
    for (i = 0; i < nblock; i++) {
        Int32 k = 0;
        for (; k < 256; k++) {
            if (local_ftabCopy[k] > 0) {
                local_ftabCopy[k]--;
                eclass8[fmap[i]] = (UChar)k;
                break;
            }
        }
    }
    for (i = 0; i < 256; i++) {
        ftabCopy[i] = local_ftabCopy[i];
    }
}
