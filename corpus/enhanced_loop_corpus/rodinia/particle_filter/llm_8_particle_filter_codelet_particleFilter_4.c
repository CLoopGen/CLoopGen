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
int i, j;
for (i = 0; i < diameter * diameter; i++) {
    if (disk[i] == 1)
        countOnes++;
}
}
