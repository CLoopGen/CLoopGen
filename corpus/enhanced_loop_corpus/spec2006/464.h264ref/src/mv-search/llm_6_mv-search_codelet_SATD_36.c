#include <stdio.h>

#include <inttypes.h>

extern int k;
extern int satd;
extern int dd;
extern int d[16];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp_satd = satd;
    for (int i = 0; i < 16; ++i) {
        int dd_val = d[i];
        temp_satd += (dd_val < 0 ? -dd_val : dd_val);
    }
    satd = temp_satd;
}
