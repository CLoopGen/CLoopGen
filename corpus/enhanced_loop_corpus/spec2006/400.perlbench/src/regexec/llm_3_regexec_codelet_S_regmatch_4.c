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
    // Variant 2: Strided memory access — process every second UTF-8 sequence instead of every one
    // Simulates reduced frequency of access with stride = 2 in effect
    int step = 0;
    for (e = locinput; m > 0 && step < m && e + PL_utf8skip[*(U8 *)e] <= PL_regeol; step += 2) {
        // First advance
        e += PL_utf8skip[*(U8 *)e];
        m--;
        // Skip next if possible (strided behavior)
        if (m > 0 && e + PL_utf8skip[*(U8 *)e] <= PL_regeol) {
            e += PL_utf8skip[*(U8 *)e];
            m--;
        }
    }
}
