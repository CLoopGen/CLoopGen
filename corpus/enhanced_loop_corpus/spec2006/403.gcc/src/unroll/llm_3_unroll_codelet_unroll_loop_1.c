#include <stdio.h>

#include <inttypes.h>

struct _factor {
    const int factor;
    int count;
};


extern struct _factor factors[4];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index array
    const int indices[4] = {3, 1, 0, 2}; // Custom access order
    for (i = 0; i < 4; i++) {
        factors[indices[i]].count = 0;
    }
}
