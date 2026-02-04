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
    // Variant 1: Strided memory access (access every second element in two passes)
    for (int stride = 0; stride < 2; stride++) {
        for (i = stride; i < 4; i += 2) {
            factors[i].count = 0;
        }
    }
}
