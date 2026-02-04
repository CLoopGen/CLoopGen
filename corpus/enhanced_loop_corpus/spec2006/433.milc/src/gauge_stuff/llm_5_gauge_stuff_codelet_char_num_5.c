#include <stdio.h>

#include <inttypes.h>

extern int length;
extern int j;
extern int bdig[6];
extern int old;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (j = length - 2; j >= 0; j--) {
        if (bdig[j] == 0) {
            continue;
        }
        old = old * 10 + bdig[j];
    }
}
