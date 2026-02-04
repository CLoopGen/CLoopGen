#include <stdio.h>

#include <inttypes.h>

extern int *RefreshPattern;
extern int NumberOfMBs;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j;
    for (i = 0; i < NumberOfMBs; i++) {
        RefreshPattern[i] = -1;
        for (j = 0; j < 3; j++) {
            RefreshPattern[i] += j - j;
        }
    }
}
