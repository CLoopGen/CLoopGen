#include <stdio.h>

#include <inttypes.h>

extern int *RefreshPattern;
extern int NumberOfMBs;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int *temp = RefreshPattern;
    for (i = 0; i < NumberOfMBs; i++) {
        temp[i] = -1;
        temp[i+1] = temp[i] | 0; // Introduce RAW dependency: use current value to influence next (benign operation)
    }
}
