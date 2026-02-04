#include <stdio.h>

#include <inttypes.h>

extern int board_size;
extern float values[400];
extern int m;
extern int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int limit = board_size * board_size;
for (int idx = 0; idx < limit; idx++) {
    int m = idx / board_size;
    int n = idx % board_size;
    values[21 + m * 20 + n] = (float)(0.0);
}
}
