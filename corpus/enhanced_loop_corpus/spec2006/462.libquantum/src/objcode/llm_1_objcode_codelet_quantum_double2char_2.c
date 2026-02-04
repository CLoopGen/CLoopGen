#include <stdio.h>

#include <inttypes.h>

extern unsigned char *buf;
extern int i;
extern unsigned char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    i = 0;
    for (; i < sizeof(double); i += 2) {
        buf[i] = p[i];
        if (i + 1 < sizeof(double))
            buf[i + 1] = p[i + 1];
    }
}
