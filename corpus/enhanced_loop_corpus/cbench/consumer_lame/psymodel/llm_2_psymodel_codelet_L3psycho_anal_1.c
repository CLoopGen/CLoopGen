#include <stdio.h>

#include <inttypes.h>

typedef float FLOAT;

extern FLOAT cw[513];
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (j = 0; j < 513; j += 2)
        cw[j] = 0.40000000000000002;
    for (j = 1; j < 513; j += 2)
        cw[j] = 0.40000000000000002;
}
