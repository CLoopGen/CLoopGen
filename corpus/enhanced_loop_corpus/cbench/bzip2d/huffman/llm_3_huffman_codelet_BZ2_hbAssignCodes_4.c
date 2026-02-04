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
    // Variant 2: Strided memory access – process elements in reverse with stride of 2
    // This changes access pattern to non-sequential, simulating cache behavior differences

    // First pass: handle even indices in reverse
    for (n = minLen; n <= maxLen; n++) {
        for (i = (alphaSize % 2 == 0 ? alphaSize - 2 : alphaSize - 1); i >= 0; i -= 2)
            if (length[i] == n) {
                code[i] = vec;
                vec++;
            }
        // Second inner loop: handle odd indices in reverse
        for (i = (alphaSize % 2 == 1 ? alphaSize - 2 : alphaSize - 1); i >= 1; i -= 2)
            if (length[i] == n) {
                code[i] = vec;
                vec++;
            }
        vec <<= 1;
    }
}
