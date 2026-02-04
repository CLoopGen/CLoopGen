#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned int md5uint;

extern  unsigned char *data;
extern md5uint x[16];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    md5uint acc = 0;
    for (i = 0; i < 16; ++i) {
        const unsigned char *p = data + 4 * i;
        acc += (unsigned int)p[0] | ((unsigned int)p[1] << 8) | ((unsigned int)p[2] << 16) | ((unsigned int)p[3] << 24);
        x[i] = acc;
    }
}
