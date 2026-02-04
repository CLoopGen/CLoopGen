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
    for (i = 0; i < nblock; i++) {
        if (ftabCopy[j] == 0) {
            j++;
            continue;
        }
        ftabCopy[j]--;
        eclass8[fmap[i]] = (UChar)j;
    }
}
