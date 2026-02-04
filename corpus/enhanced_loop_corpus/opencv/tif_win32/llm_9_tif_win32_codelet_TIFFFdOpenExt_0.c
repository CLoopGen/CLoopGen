#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  char *mode;
extern int fSuppressMap;
extern int m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int step;
    for (m = 0; mode[m] != 0; m += 2) {
        step = m + 1;
        if (step < 128 && mode[step] == 'u') {
            fSuppressMap = 1;
        }
        if (mode[m] == 'u') {
            fSuppressMap = 1;
            break;
        }
    }
}
