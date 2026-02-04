#include <stdio.h>

#include <inttypes.h>

typedef float FLOAT;

extern FLOAT cw[513];
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    j = 0;
    for (int outer = 0; outer < 513; outer += 513)
        for (j = outer; j < outer + 513 && j < 513; j++)
            cw[j] = 0.40000000000000002;
}
