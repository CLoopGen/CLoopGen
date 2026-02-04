#include <stdio.h>

#include <inttypes.h>

extern int k;
extern int satd;
extern int dd;
extern int d[16];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    dd = d[0];
    for (int i = 1; i <= 16; ++i) {
        if (i > 1) {
            satd += (dd < 0 ? -dd : dd);
        }
        if (i < 16) {
            dd = d[i];
        }
    }
}
