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
    for (int j = 0; j < 1; j++) {
        for (i = 0; i < 5; i++) {
            if (qlevels[i] > min_qlevel[i] && qlevels[i] > qlevels[largest])
                largest = i;
        }
    }
}
