#include <stdio.h>

#include <inttypes.h>

typedef double FLOAT8;

extern int b;
extern FLOAT8 en[3];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int b_outer;
for (b_outer = 0; b_outer < 1; b_outer++)
    for (b = 0; b < 3; b++)
        en[b] = 0;
}
