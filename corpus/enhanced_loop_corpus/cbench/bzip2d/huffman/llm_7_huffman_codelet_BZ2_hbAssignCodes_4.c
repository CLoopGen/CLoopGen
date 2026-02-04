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
    Int32 original_vec, shift_step;
    original_vec = vec;
    shift_step = 0;
    for (n = minLen; n <= maxLen; n++) {
        shift_step++;
        for (i = 0; i < alphaSize; i++) {
            if (length[i] == n) {
                code[i] = original_vec;
                original_vec++;
            }
        }
    }
    vec = original_vec;
    for (i = 0; i < shift_step; i++) {
        vec <<= 1;
    }
}
