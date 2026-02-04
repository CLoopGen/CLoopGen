#include <stdio.h>

#include <inttypes.h>

typedef double FLOAT8;

extern int b;
extern FLOAT8 en[3];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    en[0] = 0;
    en[1] = 0;
    en[2] = 0;
    b = 3;
}
