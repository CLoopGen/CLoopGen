#include <stdio.h>

#include <inttypes.h>

typedef double FLOAT8;

extern int b;
extern FLOAT8 en[3];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (b = 0; b < 1; b++)
    for (int inner = 0; inner < 3; inner++)
        en[inner] = 0;
}
