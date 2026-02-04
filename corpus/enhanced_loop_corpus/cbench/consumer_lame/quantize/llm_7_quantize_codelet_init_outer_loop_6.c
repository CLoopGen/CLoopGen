#include <stdio.h>

#include <inttypes.h>

typedef double FLOAT8;

extern int b;
extern FLOAT8 en[3];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (b = 2; b >= 0; b--)
        en[b] = en[(b + 1) % 3]; // Introduces loop-carried dependence: each iteration depends on next (RAW)
    en[0] = 0; // Break dependency chain by resetting after loop
}
