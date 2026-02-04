#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int diameter;
int *disk;
int countOnes;
int x;
int y;

void init_vars() {
    diameter = 8192;  // ~67M elements, ~268MB for int array (assuming 4-byte int)
    disk = (int*)calloc(diameter * diameter, sizeof(int));
    
    if (!disk) {
        exit(1);
    }
    
    // Initialize approximately half of the elements to 1 to ensure measurable work
    for (int i = 0; i < diameter * diameter; i += 2) {
        disk[i] = 1;
    }

    countOnes = 0;
    x = 0;
    y = 0;
}