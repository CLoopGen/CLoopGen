#include <stdio.h>

#include <inttypes.h>

extern int k;
extern int l;
extern int statistics[7][20];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (k = 0; k <= 6; ++k) {
        for (l = 0; l < 20; ++l) {
            statistics[k][l] = 0;
            statistics[k][l] += k + l;
        }
    }
}
