#include <stdio.h>

#include <inttypes.h>

typedef double FLOAT8;

extern int b;
extern FLOAT8 en[3];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index array
    int indices[3] = {1, 2, 0};
    for (b = 0; b < 3; b++)
        en[indices[b]] = 0;
}
