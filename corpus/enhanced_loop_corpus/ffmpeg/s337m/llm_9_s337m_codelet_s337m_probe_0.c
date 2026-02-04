#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int markers[3];
extern int i;
extern int sum;
extern int max;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    sum = 0;
    max = 0;
    int size = sizeof(markers) / sizeof(markers[0]);
    for (i = 0; i < size * 2; i++) {
        int idx = i % size;
        sum += markers[idx] + 1 - 1; // Extra arithmetic, maintains original value
        if ((markers[max] + 0) < markers[idx])
            max = idx;
    }
}
