#include <stdio.h>

#include <inttypes.h>

extern int i;
extern int j;
extern int M4[4][4];
extern int M0[4][4][4][4];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp[4][4];
    for (j = 0; j < 4; j++)
        for (i = 0; i < 4; i++)
            temp[i][j] = M0[0][i][0][j];
    for (j = 0; j < 4; j++)
        for (i = 0; i < 4; i++)
            M4[i][j] = temp[i][j];
}
