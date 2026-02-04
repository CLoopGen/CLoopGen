#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int qlevels[5];
extern int i;
extern int largest;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 5; i += 2) {
        if (i + 1 < 5) {
            if (qlevels[i] < qlevels[largest])
                largest = i;
            if (qlevels[i + 1] < qlevels[largest])
                largest = i + 1;
        } else {
            if (qlevels[i] < qlevels[largest])
                largest = i;
        }
    }
}
