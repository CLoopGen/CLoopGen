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
    factors[0].count = 0;
    for (i = 1; i < 4; i++) {
        factors[i].count = 0;
        factors[i-1].count += factors[i].count; // Introduce WAW and RAW dependencies
    }
}
