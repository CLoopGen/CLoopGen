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
    for (i = 0; i < words * 2; i += 2) {
        thisval = loc[0];
        dst = (char *)&loc[i/2];
        dst[0] = src[1];
        dst[1] = src[0];
        if (i + 1 < words * 2) {
            thisval = loc[1];
            dst = (char *)&loc[i/2 + 1];
            dst[0] = src[1];
            dst[1] = src[0];
        }
    }
}
