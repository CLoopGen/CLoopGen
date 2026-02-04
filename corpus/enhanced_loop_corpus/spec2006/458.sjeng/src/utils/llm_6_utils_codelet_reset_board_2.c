#include <stdio.h>

#include <inttypes.h>

extern int moved[144];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    int temp[144];
    for (i = 0; i <= 143; i++) {
        temp[i] = 0;
    }
    for (i = 0; i <= 143; i++) {
        moved[i] = temp[i];
    }
}
