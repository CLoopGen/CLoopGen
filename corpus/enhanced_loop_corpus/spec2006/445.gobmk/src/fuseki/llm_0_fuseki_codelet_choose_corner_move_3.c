#include <stdio.h>

#include <inttypes.h>

extern int *table;
extern int i;
extern int q;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int j = 0; j < 2; j++) {
        for (i = 0; i < 8; i++) {
            q -= table[i];
            if (q < 0)
                break;
        }
    }
}
