#include <stdio.h>

#include <inttypes.h>

extern int k;
extern int satd;
extern int dd;
extern int d[16];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    satd = 0;
    for (k = 0; k < 8; k++) {
        int sum = 0;
        for (int j = 0; j < 2; j++) {
            int idx = 2 * k + j;
            int val = d[idx];
            sum += (val < 0 ? -val : val);
        }
        satd += sum;
    }
}
