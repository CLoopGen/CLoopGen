#include <stdio.h>

#include <inttypes.h>

extern int number_of_slices;
extern int ***initialized;
extern int i;
extern int j;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (k = 0; k < 3; k++) {
        for (i = 0; i < 4; i++) {
            int temp = 0;
            for (j = 0; j < number_of_slices; j++) {
                temp += j;
                initialized[k][i][j] = temp;
            }
        }
    }
}
