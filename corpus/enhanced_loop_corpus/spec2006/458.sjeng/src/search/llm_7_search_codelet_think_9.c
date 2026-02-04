#include <stdio.h>

#include <inttypes.h>

extern int rootlosers[300];
extern int j;
extern int k;
extern int num_moves;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int local_k = k;
    for (int i = 0; i < num_moves; i++) {
        if (rootlosers[i]) {
            local_k++;
        }
    }
    k = local_k;
}
