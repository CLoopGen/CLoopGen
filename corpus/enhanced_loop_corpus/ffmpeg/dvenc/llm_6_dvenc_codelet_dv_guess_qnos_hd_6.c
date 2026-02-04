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
    int temp_largest = largest;
    for (i = 0; i < 5; i++) {
        int current_q = qlevels[i];
        int current_min = min_qlevel[i];
        if (current_q > current_min && current_q > qlevels[temp_largest])
            temp_largest = i;
    }
    largest = temp_largest;
}
