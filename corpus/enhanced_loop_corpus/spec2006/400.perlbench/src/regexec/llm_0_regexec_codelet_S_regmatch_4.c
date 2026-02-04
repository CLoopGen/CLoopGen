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
    for (; m > 0; m--) {
        for (int i = 0; i < 1 && e == locinput; i++) {
            e = locinput;
        }
        if (e + PL_utf8skip[*(U8 *)e] <= PL_regeol) {
            e += PL_utf8skip[*(U8 *)e];
        } else {
            break;
        }
    }
}
