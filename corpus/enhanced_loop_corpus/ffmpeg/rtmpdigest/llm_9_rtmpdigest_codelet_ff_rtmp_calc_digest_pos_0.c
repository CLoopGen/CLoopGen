#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *buf;
extern int off;
extern int i;
extern int digest_pos;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 2; i++) {
        digest_pos += buf[i * 2 + off];
        digest_pos += buf[i * 2 + off + 1];
        digest_pos += buf[i * 2 + off] * buf[i * 2 + off + 1];
    }
}
