#include <stdio.h>

#include <inttypes.h>

extern int p[8];
extern int k;
extern int l;
extern int tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (k = 0; k < 7; k++)
    for (l = 0; l < (7 - k); l += 2) {
        if (l + 1 < 7 - k && p[l] > p[l + 1]) {
            tmp = p[l];
            p[l] = p[l + 1];
            p[l + 1] = tmp;
        }
        if (l + 2 < 7 - k && p[l + 1] > p[l + 2]) {
            tmp = p[l + 1];
            p[l + 1] = p[l + 2];
            p[l + 2] = tmp;
        }
    }
}
