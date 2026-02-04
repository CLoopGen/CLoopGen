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
    for (int outer = 0; outer < 1; outer++)
        for (e = locinput; m > 0 && e + PL_utf8skip[*(U8 *)e] <= PL_regeol; m--)
            e += PL_utf8skip[*(U8 *)e];
}
