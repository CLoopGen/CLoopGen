#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

extern real_t arr[256][256];
extern real_t sum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int ij = 0; ij < 256 * 256; ++ij) {
    int i = ij / 256;
    int j = ij % 256;
    sum += arr[i][j];
}
}
