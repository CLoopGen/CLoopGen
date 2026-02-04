#include <stdio.h>

#include <inttypes.h>

extern int rootlosers[300];
extern int j;
extern int k;
extern int num_moves;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (j = 0; j < num_moves; j++) {
    if (rootlosers[j])
        k++;
}

}
