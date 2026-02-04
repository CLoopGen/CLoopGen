#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int diameter;
extern int *disk;
extern int countOnes;
extern int x;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int tempCount = 0;
    for (x = 0; x < diameter; x++) {
        int rowSum = 0;
        for (y = 0; y < diameter; y++) {
            rowSum += disk[x * diameter + y] == 1 ? 1 : 0;
        }
        tempCount += rowSum;
    }
    countOnes = tempCount;
}
