#include <stdio.h>

#include <inttypes.h>

extern int i;
extern int j;
extern int sad;
extern int m2[8][8];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp_sad = 0;
    for (j = 0; j < 8; j++)
        for (i = 0; i < 8; i++)
            temp_sad += ((m2[j][i] < 0) ? -m2[j][i] : m2[j][i]);
    sad += temp_sad;
}
