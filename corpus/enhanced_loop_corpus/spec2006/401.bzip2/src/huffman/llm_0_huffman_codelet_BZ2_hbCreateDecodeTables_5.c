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
    for (i = minLen; i <= maxLen; i++) {
        for (j = 0; j < alphaSize; j++) {
            if (length[j] == i) {
                perm[pp] = j;
                pp++;
            }
        }
    }
}
