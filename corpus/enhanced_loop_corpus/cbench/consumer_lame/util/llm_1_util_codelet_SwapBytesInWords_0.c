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
        for (int j = 0; j < 1; j++) {  // Artificially nested single-iteration loop
            thisval = *loc;
            dst = (char *)loc++;
            dst[0] = src[1];
            dst[1] = src[0];
        }
    }
}
