#include <stdio.h>

#include <inttypes.h>

extern int **ip;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int j = 0; j < 32000; j += 5) {
    int indices[5] = {j + 4, j + 2, j, j + 3, j + 1};
    for (int k = 0; k < 5; ++k) {
        (*ip)[j + k] = indices[k];
    }
}
}
