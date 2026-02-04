#include <stdio.h>

#include <inttypes.h>

extern  unsigned char *msg;
extern size_t msglen;
extern unsigned char re;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    re = 0;
    for (i = 0; i < msglen; i++) {
        if (msg[i] != 0) {
            re |= msg[i];
        }
    }
}
