#include <stdio.h>

#include <inttypes.h>

extern short *loc;
extern int words;
extern int i;
extern short thisval;
extern char *dst;
extern char *src;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < words; i++) {
    thisval = *loc;
    dst = (char *)loc++;
    if (thisval > 0) {
        dst[0] = src[1];
        dst[1] = src[0];
    } else {
        continue;
    }
}
}
