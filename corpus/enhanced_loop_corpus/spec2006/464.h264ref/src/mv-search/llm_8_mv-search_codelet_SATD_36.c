#include <stdio.h>

#include <inttypes.h>

extern int k;
extern int satd;
extern int dd;
extern int d[16];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp_satd = 0;
    for (k = 0; k < 16; k += 2) {
        int val1 = d[k];
        int val2 = k + 1 < 16 ? d[k + 1] : 0;
        temp_satd += (val1 < 0 ? -val1 : val1) + (val2 < 0 ? -val2 : val2);
    }
    satd += temp_satd;
}
