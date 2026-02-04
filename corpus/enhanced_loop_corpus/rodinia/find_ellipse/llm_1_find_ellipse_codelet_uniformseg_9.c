#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double dist[36];
extern double dsum[36];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 1; i < 36; i++) {
        dsum[i] = dist[i];
        for (int k = 0; k < 1; k++) {
            dsum[i] += dsum[i - 1];
        }
    }
}
