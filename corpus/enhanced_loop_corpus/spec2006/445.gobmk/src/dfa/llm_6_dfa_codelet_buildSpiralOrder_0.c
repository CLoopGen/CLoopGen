#include <stdio.h>

#include <inttypes.h>

extern int mark[7056];
extern int ii;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int base = 0;
    for (ii = 0; ii < 21 * 4; ii++) {
        for (int j = 0; j < 21 * 4; j++) {
            mark[base + j] = 1;
        }
        base += 21 * 4;
    }
}
