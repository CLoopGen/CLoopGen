#include <stdio.h>

#include <inttypes.h>

extern int rootlosers[300];
extern int j;
extern int k;
extern int num_moves;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    j = 0;
    for (; j < num_moves; ) {
        if (rootlosers[j]) {
            k++;
        }
        j++;
        {
            continue;
        }
    }
}
