#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int qlevels[5];
extern int i;
extern int largest;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    largest = 0;
    for (i = 4; i >= 0; i--) {
        int val = qlevels[i];
        int curr = qlevels[largest];
        if (val < curr) {
            largest = i;
        }
    }
}
