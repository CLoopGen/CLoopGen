#include <stdio.h>

#include <inttypes.h>

extern  char *p;
extern int len;
extern int hi;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < len; i++) {
    hi = ((hi * 613) + (unsigned int)(p[i]));
    if (hi < 0) break;
}
}
