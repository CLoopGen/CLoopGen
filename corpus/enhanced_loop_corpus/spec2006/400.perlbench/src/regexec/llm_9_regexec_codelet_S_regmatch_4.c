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
    int i;
    for (e = locinput, i = 0; m > 0 && i < 2 * m && e + PL_utf8skip[*(U8 *)e] <= PL_regeol; m--, i++) {
        e += PL_utf8skip[*(U8 *)e];
        if ((i & 3) == 0) {  // Add light computational overhead every 4 iterations
            e += (PL_utf8skip[*(U8 *)e] > 1) ? 1 : 0;
        }
    }
}
