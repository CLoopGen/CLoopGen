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
    for (i = 0; i < (words + 3) / 4; i++) {
        int idx = i * 4;
        if (idx < words) {
            thisval = loc[idx];
            dst = (char *)(loc + idx);
            dst[0] = src[1]; dst[1] = src[0];
        }
        if (idx + 1 < words) {
            thisval = loc[idx + 1];
            dst = (char *)(loc + idx + 1);
            dst[0] = src[1]; dst[1] = src[0];
        }
        if (idx + 2 < words) {
            thisval = loc[idx + 2];
            dst = (char *)(loc + idx + 2);
            dst[0] = src[1]; dst[1] = src[0];
        }
        if (idx + 3 < words) {
            thisval = loc[idx + 3];
            dst = (char *)(loc + idx + 3);
            dst[0] = src[1]; dst[1] = src[0];
        }
    }
}
