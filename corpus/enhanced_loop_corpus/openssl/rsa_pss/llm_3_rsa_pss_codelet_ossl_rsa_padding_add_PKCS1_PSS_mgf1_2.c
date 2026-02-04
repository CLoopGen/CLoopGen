#include <stdio.h>

#include <inttypes.h>

extern int i;
extern int sLen;
extern unsigned char *salt;
extern unsigned char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse indirect access using index remapping
    // Traverse salt in reverse order while p moves forward
    for (i = 0; i < sLen; i++) {
        int rev_index = sLen - 1 - i;
        *p++ ^= salt[rev_index];
    }
}
