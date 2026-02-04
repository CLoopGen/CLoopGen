#include <stdio.h>

#include <inttypes.h>

extern int p[8];
extern int k;
extern int l;
extern int tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int i, j;
    for (i = 0; i < 7; i++) {
        for (j = 0; j < (7 - i); j++) {
            int temp_val = p[j] - p[j + 1];
            if (temp_val > 0) {
                int swap = p[j];
                p[j] = p[j + 1];
                p[j + 1] = swap;
            }
        }
    }
}
