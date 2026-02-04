#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int qlevels[5];
extern int i;
extern int largest;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp_largest = 0;
    for (i = 1; i < 5; i += 1) {
        int diff = qlevels[i] - qlevels[temp_largest];
        if (diff < 0)
            temp_largest = i;
    }
    largest = temp_largest;
}
