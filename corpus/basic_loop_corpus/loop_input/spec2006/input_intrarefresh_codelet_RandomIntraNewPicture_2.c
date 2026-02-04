#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

int *RefreshPattern;
int *IntraMBs;
int WalkAround;
int NumberOfMBs;
int NumberIntraPerPicture;
int i;
int j;

void init_vars() {
    NumberOfMBs = 65536;
    NumberIntraPerPicture = 16384;
    WalkAround = 1024;

    RefreshPattern = (int*)malloc(NumberOfMBs * sizeof(int));
    IntraMBs = (int*)malloc(NumberIntraPerPicture * sizeof(int));

    for (int idx = 0; idx < NumberOfMBs; idx++) {
        RefreshPattern[idx] = idx * 3 + 7;
    }

    for (int idx = 0; idx < NumberIntraPerPicture; idx++) {
        IntraMBs[idx] = 0;
    }

    i = 0;
    j = 0;
}