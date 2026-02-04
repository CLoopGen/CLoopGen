#include <stdio.h>

#include <inttypes.h>

typedef double FLOAT8;

extern int b;
extern FLOAT8 en[3];
extern FLOAT8 mx;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect array access using an index map (simulating non-sequential access pattern)
    int indices[3] = {1, 2, 0};  // Define a custom access order
    for (b = 0; b < 3; b++)
        mx = ((mx) > (en[indices[b]]) ? (mx) : (en[indices[b]]));
}
