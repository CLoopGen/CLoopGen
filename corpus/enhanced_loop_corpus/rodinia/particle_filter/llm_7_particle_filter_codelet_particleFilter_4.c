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
    countOnes = 0;
    for (x = 0; x < diameter; x++) {
        for (y = 0; y < diameter; y++) {
            int index = x * diameter + y;
            int val = disk[index];
            // Introduce artificial WAW and WAR dependency via temporary update pattern
            if (val == 1) {
                countOnes = countOnes + 1;
            }
        }
    }
}
