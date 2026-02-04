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
int j;
for (i = 0; i < 4; i++) {
    factors[i].count = 0;
    for (j = 0; j < 100; j++) {
        factors[i].count += j * factors[i].factor;
    }
}
}
