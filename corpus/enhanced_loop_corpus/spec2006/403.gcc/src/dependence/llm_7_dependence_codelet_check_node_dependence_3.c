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
    direction[1][0] = undef;
    distance[1][0] = 0;
    for (j = 2; j < 13; j++) {
        direction[j][0] = direction[j-1][0];
        distance[j][0] = distance[j-1][0] + 1;
    }
}
