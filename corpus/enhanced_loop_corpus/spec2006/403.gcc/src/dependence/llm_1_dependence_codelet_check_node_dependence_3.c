#include <stdio.h>

#include <inttypes.h>

enum direction_type {
    lt,
    le,
    eq,
    gt,
    ge,
    star,
    independent,
    undef
};


extern int distance[13][13];
extern int j;
extern enum direction_type direction[13][13];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 1; j < 13; j++) {
    for (int k = 0; k < 1; k++) {
        direction[j][0] = undef;
        distance[j][0] = 0;
    }
}
}
