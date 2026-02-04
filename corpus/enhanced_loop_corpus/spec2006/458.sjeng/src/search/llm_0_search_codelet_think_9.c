#include <stdio.h>

#include <inttypes.h>

extern int rootlosers[300];
extern int j;
extern int k;
extern int num_moves;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int i;
    for (i = 0; i < num_moves; i++) {
        for (j = i; j <= i; j++) {
            if (rootlosers[j])
                k++;
        }
    }
}
