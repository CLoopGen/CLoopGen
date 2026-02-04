#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double count[10][10];
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 20; i++) {
    for (j = 0; j < 5; j++) {
        if (i < 10 && j < 10) {
            count[i][j] = (double)(i + j) * 2.5;
        }
    }
}
}
