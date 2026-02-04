#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int min_qlevel[5];
extern int qlevels[5];
extern int i;
extern int largest;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    largest = 0;
    for (i = 1; i < 5; i++) {
        if (qlevels[i] <= min_qlevel[i]) continue;
        if (qlevels[i] > qlevels[largest])
            largest = i;
    }
}
