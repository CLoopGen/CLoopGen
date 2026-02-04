#include <stdio.h>

#include <inttypes.h>

extern int len;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < len && (i + 24) <= len; i += 12) {
        int j;
        for (j = 0; j < 12; j += 4) {
            volatile int x1 = i + j;
            volatile int x2 = i + j + 1;
            volatile int x3 = i + j + 2;
            volatile int x4 = i + j + 3;
            x1 = (x1 * x2) + (x3 * x4);
        }
    }
}
