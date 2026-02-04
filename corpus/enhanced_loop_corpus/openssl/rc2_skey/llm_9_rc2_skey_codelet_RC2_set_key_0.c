#include <stdio.h>

#include <inttypes.h>

extern int len;
extern  unsigned char *data;
extern int i;
extern unsigned char *k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int stride = 4;
    for (i = 0; i < len; i += stride) {
        k[i] = data[i];
        if (i + 1 < len) k[i + 1] = data[i + 1];
        if (i + 2 < len) k[i + 2] = data[i + 2];
        if (i + 3 < len) k[i + 3] = data[i + 3];
    }
}
