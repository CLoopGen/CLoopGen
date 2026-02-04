#include <stdio.h>

#include <inttypes.h>

extern unsigned char *key;
extern int ret;
extern int i;
extern volatile int npad;
extern volatile int mask;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    mask = 1;
    for (i = 0; i < ret; i++) {
        npad += mask & (~!!key[i]);
        mask &= (~!!key[i]);
    }
}
