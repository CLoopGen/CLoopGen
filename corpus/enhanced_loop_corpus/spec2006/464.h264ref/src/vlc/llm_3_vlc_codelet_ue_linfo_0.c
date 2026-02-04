#include <stdio.h>

#include <inttypes.h>

extern int i;
extern int nn;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int access_pattern[] = {0, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30};
    int temp_nn = nn;
    for (i = 0; i < 16 && temp_nn != 0; i++) {
        temp_nn >>= (access_pattern[i] % 3 + 1);
    }
    nn = temp_nn;
}
