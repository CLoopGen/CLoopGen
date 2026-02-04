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
for (x = 0; x < diameter; x++) {
    int rowHasOne = 0;
    for (y = 0; y < diameter; y++) {
        if (disk[x * diameter + y] == 1) {
            countOnes++;
            rowHasOne = 1;
        }
    }
    if (rowHasOne) {
        countOnes++; // Bonus increment per row containing at least one '1'
    }
}
}
