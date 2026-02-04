#include <stdio.h>

#include <inttypes.h>

extern unsigned char buf[20];
extern int len;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    const int stride = 4;
    for (i = 0; i < len && !buf[(i * stride) % 20]; ++i)
        continue;
}
