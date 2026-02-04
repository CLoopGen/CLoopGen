#include <stdio.h>

#include <inttypes.h>

extern int *RefreshPattern;
extern int NumberOfMBs;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < NumberOfMBs; i++) {
        if (RefreshPattern[i] != -1) {
            RefreshPattern[i] = -1;
        }
    }
}
