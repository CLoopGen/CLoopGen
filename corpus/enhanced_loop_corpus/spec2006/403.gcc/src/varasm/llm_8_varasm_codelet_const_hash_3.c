#include <stdio.h>

#include <inttypes.h>

extern  char *p;
extern int len;
extern int hi;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < len; i += 2) {
        if (i + 1 < len) {
            hi = ((hi * 613) + (unsigned int)(p[i])) ^ ((unsigned int)(p[i + 1]) * 307);
        } else {
            hi = ((hi * 613) + (unsigned int)(p[i]));
        }
    }
}
