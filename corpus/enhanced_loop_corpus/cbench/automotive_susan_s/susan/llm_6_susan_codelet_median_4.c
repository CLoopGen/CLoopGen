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
        int swapped = 0;
        for (j = 0; j < 7 - i - 1; j++) {
            if (p[j] > p[j + 1]) {
                tmp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = tmp;
                swapped = 1;
            }
        }
        if (!swapped) break;
    }
}
