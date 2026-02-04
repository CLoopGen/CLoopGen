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
    int idx = 0;
    for (x = 0; x < diameter * diameter; x++) {
        if (disk[x] == 1)
            countOnes++;
    }
}
