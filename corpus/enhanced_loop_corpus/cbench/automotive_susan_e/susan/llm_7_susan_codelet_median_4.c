#include <stdio.h>

#include <inttypes.h>

extern int p[8];
extern int k;
extern int l;
extern int tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int k, l;
    int local_p[8];
    for (k = 0; k < 8; k++) {
        local_p[k] = p[k];
    }
    for (k = 0; k < 7; k++) {
        for (l = 0; l < (7 - k); l++) {
            if (local_p[l] > local_p[l + 1]) {
                int tmp = local_p[l];
                local_p[l] = local_p[l + 1];
                local_p[l + 1] = tmp;
            }
        }
    }
    for (k = 0; k < 8; k++) {
        p[k] = local_p[k];
    }
}
