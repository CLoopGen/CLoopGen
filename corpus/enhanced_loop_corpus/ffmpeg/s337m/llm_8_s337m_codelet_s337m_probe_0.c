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
    for (i = 0; i < size; i += 2) {
        sum += markers[i];
        if (i + 1 < size) {
            sum += markers[i + 1];
        }
        if (markers[max] < markers[i]) {
            max = i;
        }
    }
}
