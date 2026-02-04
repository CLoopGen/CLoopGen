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
for (i = 0; i < 8; ++i) {
    const unsigned char *p1 = data + 4 * i;
    const unsigned char *p2 = data + 4 * (i + 8);
    x[i] = (unsigned int)p1[0] | ((unsigned int)p1[1] << 8) | ((unsigned int)p1[2] << 16) | ((unsigned int)p1[3] << 24);
    x[i + 8] = (unsigned int)p2[0] | ((unsigned int)p2[1] << 8) | ((unsigned int)p2[2] << 16) | ((unsigned int)p2[3] << 24);
}
}
