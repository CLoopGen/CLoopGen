#include <stdio.h>

#include <inttypes.h>

extern int i;
extern int sLen;
extern unsigned char *salt;
extern unsigned char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (sLen <= 0) return;
    for (i = 0; i < sLen; i++) {
        *p++ ^= salt[i];
    }
}
