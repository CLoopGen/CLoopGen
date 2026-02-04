#include <stdio.h>

#include <inttypes.h>

typedef float FLOAT;

extern FLOAT cw[513];
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int indices[513];
    for (j = 0; j < 513; j++)
        indices[j] = j;
    for (j = 0; j < 513; j++)
        cw[indices[j]] = 0.40000000000000002;
}
