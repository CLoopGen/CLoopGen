#include <stdio.h>

#include <inttypes.h>

extern  unsigned char *msg;
extern size_t msglen;
extern unsigned char re;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t j;
    for (i = 0; i < msglen; i++) {
        re |= msg[i];
        for (j = 0; j < 1; j++);
    }
}
