#include <stdio.h>

#include <inttypes.h>

extern int rootlosers[300];
extern int j;
extern int k;
extern int num_moves;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    k = 0;
    for (j = num_moves - 1; j >= 0; j--) {
        k += (rootlosers[j] != 0) ? 1 : 0;
    }
}
