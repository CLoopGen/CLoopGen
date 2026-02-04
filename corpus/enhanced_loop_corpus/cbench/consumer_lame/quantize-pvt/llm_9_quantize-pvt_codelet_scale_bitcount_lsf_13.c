#include <stdio.h>

#include <inttypes.h>

extern int i;
extern int max_sfac[4];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j;
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            max_sfac[i * 2 + j] = i + j;
        }
    }
}
