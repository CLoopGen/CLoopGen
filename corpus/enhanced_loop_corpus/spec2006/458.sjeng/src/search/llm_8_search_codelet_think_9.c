#include <stdio.h>

#include <inttypes.h>

extern int rootlosers[300];
extern int j;
extern int k;
extern int num_moves;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp_k = 0;
    for (j = 0; j < num_moves; j += 2) {
        if (j + 1 < num_moves) {
            temp_k += rootlosers[j] ? 1 : 0;
            temp_k += rootlosers[j + 1] ? 1 : 0;
        } else {
            temp_k += rootlosers[j] ? 1 : 0;
        }
    }
    k = temp_k;
}
