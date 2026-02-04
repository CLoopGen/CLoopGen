#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern int square;
extern int l;
extern int m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Higher trip count with lighter per-iteration computation, unrolled pattern simulation
    // This variant decreases the step size magnitude (from -11 to -1), significantly increasing iterations,
    // but simplifies condition to a direct comparison without complex dependencies, favoring higher throughput
    // on predictable loops. Still maintains dependency on original array and exit condition.
    for (l = square - 11; l >= 0 && board[l] == 13; l -= 1) {
        m++;
    }
}
