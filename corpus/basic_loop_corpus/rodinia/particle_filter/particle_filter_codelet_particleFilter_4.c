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
    for (y = 0; y < diameter; y++) {
        if (disk[x * diameter + y] == 1)
            countOnes++;
    }
}

}
