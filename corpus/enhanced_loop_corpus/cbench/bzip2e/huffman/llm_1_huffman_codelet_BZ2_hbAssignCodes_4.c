#include <stdio.h>

#include <inttypes.h>

typedef int Int32;

typedef unsigned char UChar;

extern Int32 *code;
extern UChar *length;
extern Int32 minLen;
extern Int32 maxLen;
extern Int32 alphaSize;
extern Int32 n;
extern Int32 vec;
extern Int32 i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (n = minLen; n <= maxLen; n++) {
    for (i = 0; i < alphaSize; i += 2) {
        if (i < alphaSize && length[i] == n) {
            code[i] = vec;
            vec++;
        }
        if (i + 1 < alphaSize && length[i + 1] == n) {
            code[i + 1] = vec;
            vec++;
        }
    }
    vec <<= 1;
}
}
