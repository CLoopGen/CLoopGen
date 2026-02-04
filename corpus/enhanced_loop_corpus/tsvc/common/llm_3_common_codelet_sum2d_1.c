#include <stdio.h>

#include <inttypes.h>

typedef float real_t;

extern real_t arr[256][256];
extern real_t sum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int i = 0; i < 256; i++) {
    for (int j = 0; j < 256; j += 4) {
        sum += arr[i][j];
        if (j + 1 < 256) sum += arr[i][j + 1];
        if (j + 2 < 256) sum += arr[i][j + 2];
        if (j + 3 < 256) sum += arr[i][j + 3];
    }
}
}
