#include <stdio.h>

#include <inttypes.h>

extern  char *p;
extern int len;
extern int hi;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < len * 2; i++) {
        hi = ((hi * 613) + (unsigned int)(p[i % len])) + (i % 5 == 0 ? 109 : 0);
    }
}
