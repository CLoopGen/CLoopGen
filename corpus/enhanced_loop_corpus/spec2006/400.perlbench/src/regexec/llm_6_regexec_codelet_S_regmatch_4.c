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
    char *temp_e = locinput;
    int temp_m = m;
    for (; temp_m > 0 && temp_e + PL_utf8skip[*(U8 *)temp_e] <= PL_regeol; temp_m--) {
        temp_e += PL_utf8skip[*(U8 *)temp_e];
    }
    e = temp_e;
}
