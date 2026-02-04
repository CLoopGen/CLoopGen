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
for (i = 0; i < 4; i++)
    digest_pos += buf[i + off];

}
