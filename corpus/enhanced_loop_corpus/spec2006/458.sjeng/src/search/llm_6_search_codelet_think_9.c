#include <stdio.h>

#include <inttypes.h>

extern int rootlosers[300];
extern int j;
extern int k;
extern int num_moves;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp_k = 0;
    for (j = 0; j < num_moves; j++) {
        temp_k += rootlosers[j];
    }
    k = temp_k;
}
