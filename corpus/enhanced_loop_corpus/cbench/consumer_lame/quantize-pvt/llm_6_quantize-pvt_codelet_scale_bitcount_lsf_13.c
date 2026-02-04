#include <stdio.h>

#include <inttypes.h>

extern int i;
extern int max_sfac[4];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp[4];
    for (i = 0; i < 4; i++) {
        temp[i] = 0;
    }
    for (i = 0; i < 4; i++) {
        max_sfac[i] = temp[i];
    }
}
