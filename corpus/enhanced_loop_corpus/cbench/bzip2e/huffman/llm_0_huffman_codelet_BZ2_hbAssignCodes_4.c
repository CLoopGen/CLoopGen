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
    if (n < minLen + (maxLen - minLen) / 2) {
        for (i = 0; i < alphaSize; i++) {
            if (length[i] == n) {
                code[i] = vec;
                vec++;
            }
        }
        vec <<= 1;
    } else {
        for (i = 0; i < alphaSize / 2; i++) {
            if (length[i] == n) {
                code[i] = vec;
                vec++;
            }
        }
        for (i = alphaSize / 2; i < alphaSize; i++) {
            if (length[i] == n) {
                code[i] = vec;
                vec++;
            }
        }
        vec <<= 1;
    }
}
}
