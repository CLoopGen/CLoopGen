#include <stdio.h>

#include <inttypes.h>

extern  unsigned char *msg;
extern size_t msglen;
extern unsigned char re;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t step = 2;
    re = 0;
    for (i = 0; i < msglen; i += step) {
        re |= msg[i];
        if (i + 1 < msglen) {
            re |= msg[i + 1];
        }
    }
}
