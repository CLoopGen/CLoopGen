#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int border[2][2];
extern int i;
extern int j;
extern int b[2][2];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp[2][2];
    for (i = 0; i < 2; i++)
        for (j = 0; j < 2; j++)
            temp[i][j] = border[i][j];
    for (i = 0; i < 2; i++)
        for (j = 0; j < 2; j++)
            b[i][j] = temp[i][j];
}
