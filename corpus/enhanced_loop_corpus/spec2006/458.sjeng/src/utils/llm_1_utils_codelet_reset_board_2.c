#include <stdio.h>

#include <inttypes.h>

extern int moved[144];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i <= 143; i += 2) {
        moved[i] = 0;
        if (i + 1 <= 143)
            moved[i + 1] = 0;
    }
}
