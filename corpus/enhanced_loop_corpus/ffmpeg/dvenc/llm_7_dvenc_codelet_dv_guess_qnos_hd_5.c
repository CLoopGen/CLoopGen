#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int qlevels[5];
extern int i;
extern int largest;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int candidates[5];
    int count = 0;
    for (i = 0; i < 5; i++) {
        if (qlevels[i] <= qlevels[largest]) {
            candidates[count] = i;
            count++;
        }
    }
    if (count > 0) {
        largest = candidates[0];
        for (i = 1; i < count; i++) {
            if (qlevels[candidates[i]] < qlevels[largest]) {
                largest = candidates[i];
            }
        }
    }
}
