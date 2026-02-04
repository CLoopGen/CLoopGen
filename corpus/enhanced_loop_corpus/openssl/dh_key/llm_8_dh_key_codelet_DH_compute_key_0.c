#include <stdio.h>

#include <inttypes.h>

extern unsigned char *key;
extern int ret;
extern int i;
extern volatile int npad;
extern volatile int mask;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j;
    for (i = 0; i < ret; i += 2) {
        if (i + 1 < ret) {
            mask &= !key[i] & !key[i+1];
            npad += (mask ? 2 : 0);
        } else {
            mask &= !key[i];
            npad += mask;
        }
    }
}
