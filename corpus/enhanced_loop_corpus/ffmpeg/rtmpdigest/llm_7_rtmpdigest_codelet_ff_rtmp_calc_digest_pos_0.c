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
    int j;
    int local_digest_pos = digest_pos;
    for (i = 0, j = 3; i < 4; i++, j--)
        local_digest_pos += buf[j + off];
    digest_pos = local_digest_pos;
}
