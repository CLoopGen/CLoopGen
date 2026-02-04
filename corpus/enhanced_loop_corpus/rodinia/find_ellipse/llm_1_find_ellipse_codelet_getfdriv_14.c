#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int N;
extern int *aindex;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 1; i < N; i++) {
        for (int j = 0; j < 1; j++) {
            aindex[i] = i - 1;
        }
    }
}
