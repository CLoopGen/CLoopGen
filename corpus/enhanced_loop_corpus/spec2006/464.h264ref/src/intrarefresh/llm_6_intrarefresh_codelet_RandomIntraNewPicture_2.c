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
    int temp;
    for (j = 0, i = WalkAround; j < NumberIntraPerPicture; j++, i++) {
        temp = RefreshPattern[i % NumberOfMBs];
        IntraMBs[j] = temp;
    }
}
