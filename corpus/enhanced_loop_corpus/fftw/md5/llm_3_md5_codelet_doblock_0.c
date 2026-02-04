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
const unsigned char *p = data;
for (i = 0; i < 16; ++i) {
    int idx = i * 4;
    x[i] = (unsigned int)p[idx] | ((unsigned int)p[idx + 1] << 8) | ((unsigned int)p[idx + 2] << 16) | ((unsigned int)p[idx + 3] << 24);
}
}
