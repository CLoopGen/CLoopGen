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
    for (i = 0; i < 8; i += 2) {
        digest_pos += buf[i + off];
        digest_pos += buf[i + off + 1];
    }
}
