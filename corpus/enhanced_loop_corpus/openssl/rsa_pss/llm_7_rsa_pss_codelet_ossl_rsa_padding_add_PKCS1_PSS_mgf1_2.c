#include <stdio.h>

#include <inttypes.h>

extern int i;
extern int sLen;
extern unsigned char *salt;
extern unsigned char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int k;
    unsigned char *p_local = p;
    for (k = 0; k < sLen; k += 2) {
        if (k + 1 < sLen) {
            p_local[k] ^= salt[k];
            p_local[k + 1] ^= salt[k + 1];
        } else {
            p_local[k] ^= salt[k];
        }
    }
    p = p_local + sLen;
}
