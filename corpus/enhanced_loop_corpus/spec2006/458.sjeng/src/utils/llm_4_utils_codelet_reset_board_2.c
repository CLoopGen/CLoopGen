#include <stdio.h>

#include <inttypes.h>

extern int moved[144];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i <= 143; i++) {
        if (i % 2 == 0) {
            moved[i] = 0;
        } else {
            continue;
        }
    }
}
