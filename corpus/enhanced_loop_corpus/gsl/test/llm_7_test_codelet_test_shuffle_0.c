#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double count[10][10];
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double temp[10];
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            temp[j] = 0;
        }
        for (j = 0; j < 10; j++) {
            count[i][j] = temp[j];
        }
    }
}
