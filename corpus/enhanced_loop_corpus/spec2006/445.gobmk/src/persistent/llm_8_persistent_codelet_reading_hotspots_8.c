#include <stdio.h>

#include <inttypes.h>

extern int board_size;
extern float values[400];
extern int m;
extern int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (m = 0; m < board_size; m++) {
    float *row_base = &values[(20 + m) * 20];
    for (n = 0; n < board_size; n += 4) {
        row_base[n] = 0.0f;
        if (n+1 < board_size) row_base[n+1] = 0.0f;
        if (n+2 < board_size) row_base[n+2] = 0.0f;
        if (n+3 < board_size) row_base[n+3] = 0.0f;
    }
}
}
