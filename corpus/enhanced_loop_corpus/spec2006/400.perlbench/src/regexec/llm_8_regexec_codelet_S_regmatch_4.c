#include <stdio.h>

#include <inttypes.h>

typedef unsigned char U8;

extern char *e;
extern int m;
extern const unsigned char PL_utf8skip[];
extern char *PL_regeol;
extern char *locinput;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (e = locinput; m > 0 && e < PL_regeol; m--) {
        int skip = PL_utf8skip[*(U8 *)e];
        if (e + skip <= PL_regeol) {
            e += skip;
        } else {
            break;
        }
    }
}
