#include <stdio.h>

#include <inttypes.h>

typedef float FLOAT;

extern FLOAT cw[513];
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int k = 0; k < 1; k++)
        for (j = 0; j < 513; j++)
            cw[j] = 0.40000000000000002;
}
