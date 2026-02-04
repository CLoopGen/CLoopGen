#include <stdio.h>

#include <inttypes.h>

extern int moved[144];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i <= 143; i++) {
        moved[i] = 0;
        if (i == 72) {
            break;
        }
    }
}
