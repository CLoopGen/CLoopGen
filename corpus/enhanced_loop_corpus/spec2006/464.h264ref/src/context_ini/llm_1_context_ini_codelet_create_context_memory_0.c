#include <stdio.h>

#include <inttypes.h>

extern int number_of_slices;
extern int ***initialized;
extern int i;
extern int j;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 4; i++) {
    for (j = 0; j < number_of_slices; j++) {
        initialized[0][i][j] = 0;
        initialized[1][i][j] = 0;
        initialized[2][i][j] = 0;
    }
}
}
