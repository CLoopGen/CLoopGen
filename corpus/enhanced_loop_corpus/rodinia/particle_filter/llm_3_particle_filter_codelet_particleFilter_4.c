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
    int stride = diameter + 1;
    for (x = 0; x < diameter; x++) {
        for (y = 0; y < diameter; y += 2) {
            int idx1 = x * diameter + y;
            int idx2 = idx1 + 1;
            if (y < diameter && disk[idx1] == 1)
                countOnes++;
            if (y + 1 < diameter && disk[idx2] == 1)
                countOnes++;
        }
    }
}
