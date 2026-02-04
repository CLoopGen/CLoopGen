#include <stdio.h>

#include <inttypes.h>

extern unsigned char buf[20];
extern int len;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    i = 0;
    int limit = len > 20 ? 20 : len;
    for (; i < limit && !(buf[i] & 1); ++i) {
        buf[i] += 2;
    }
}
