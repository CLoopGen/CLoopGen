#include <stdio.h>

#include <inttypes.h>

extern int i;
extern int sLen;
extern unsigned char *salt;
extern unsigned char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int j;
for (j = 0; j < sLen; j++) {
    for (i = 0; i < 1; i++) {
        *p++ ^= salt[j];
    }
}
}
