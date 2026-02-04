#include <stdio.h>

#include <inttypes.h>

extern int mark[7056];
extern int ii;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int limit = 21 * 4;
    for (int i = 0; i < limit; i++) {
        for (int j = 0; j < limit; j++) {
            mark[i * limit + j] = 1;
        }
    }
}
