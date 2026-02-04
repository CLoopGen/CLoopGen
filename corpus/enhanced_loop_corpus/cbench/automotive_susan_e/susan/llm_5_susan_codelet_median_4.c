#include <stdio.h>

#include <inttypes.h>

extern int p[8];
extern int k;
extern int l;
extern int tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (k = 0; k < 7; k++) {
    int swapped = 0;
    for (l = 0; l < (7 - k); l++) {
        if (p[l] > p[l + 1]) {
            tmp = p[l];
            p[l] = p[l + 1];
            p[l + 1] = tmp;
            swapped = 1;
        }
    }
    if (!swapped) break;
}
}
