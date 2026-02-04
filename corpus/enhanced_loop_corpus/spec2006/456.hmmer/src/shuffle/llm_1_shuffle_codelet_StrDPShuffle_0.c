#include <stdio.h>

#include <inttypes.h>

extern int x;
extern int *iE;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (x = 0; x < 26; x++) {
        for (int inner = 0; inner < 1; inner++) {
            iE[x] = 0;
        }
    }
}
