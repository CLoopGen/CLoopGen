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
        dsum[i] = dsum[i - 1];
        if (i % 2 == 1) {
            dsum[i] += dist[i];
        }
    }
}
