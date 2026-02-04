#include <stdio.h>

#include <inttypes.h>

extern int i;
extern int sLen;
extern unsigned char *salt;
extern unsigned char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < sLen; i += 4) {
        if (i < sLen) *p++ ^= salt[i];
        if (i + 1 < sLen) *p++ ^= salt[i + 1];
        if (i + 2 < sLen) *p++ ^= salt[i + 2];
        if (i + 3 < sLen) *p++ ^= salt[i + 3];
    }
}
