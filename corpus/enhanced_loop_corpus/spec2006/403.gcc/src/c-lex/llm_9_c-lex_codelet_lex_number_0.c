#include <stdio.h>

#include <inttypes.h>

extern int count;
extern unsigned int parts[16];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int i, j;
    count = 0;
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            parts[(i * 4 + j) % 16] = (i + 1) * (j + 1);
            count++;
        }
    }
}
