#include <stdio.h>

#include <inttypes.h>

extern int i;
extern int sLen;
extern unsigned char *salt;
extern unsigned char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j;
    for (i = 0; i < sLen * 2; i += 2) {
        j = i % sLen;
        *p++ ^= salt[j];
        if (i + 1 < sLen * 2)
            *p++ ^= salt[(j + 1) % sLen];
    }
}
