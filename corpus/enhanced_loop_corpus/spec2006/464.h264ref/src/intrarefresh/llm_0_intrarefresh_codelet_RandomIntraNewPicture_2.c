#include <stdio.h>

#include <inttypes.h>

extern int *RefreshPattern;
extern int *IntraMBs;
extern int WalkAround;
extern int NumberOfMBs;
extern int NumberIntraPerPicture;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (j = 0; j < NumberIntraPerPicture; j++) {
        i = WalkAround + j;
        IntraMBs[j] = RefreshPattern[i % NumberOfMBs];
    }
}
