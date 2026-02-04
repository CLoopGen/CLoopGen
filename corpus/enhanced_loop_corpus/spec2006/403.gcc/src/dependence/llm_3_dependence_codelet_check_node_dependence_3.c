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
    // Variant 2: Strided memory access with reverse iteration and stride of 2 (simulating non-unit stride)
    // This variant accesses every second element in reverse order, creating a strided access pattern
    int j;
    for (j = 12; j >= 1; j -= 2) {  // Reverse and strided by 2
        direction[j][0] = undef;
        distance[j][0] = 0;
        // Handle the next index if within bounds (to maintain same total iterations conceptually)
        if (j - 1 >= 1) {
            direction[j-1][0] = undef;
            distance[j-1][0] = 0;
        }
    }
}
