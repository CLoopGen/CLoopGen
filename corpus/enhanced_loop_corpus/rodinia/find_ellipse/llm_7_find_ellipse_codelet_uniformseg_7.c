#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double dist[36];
extern double dsum[36];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 1; i < 36; i += 2) {
        if (i + 1 < 36) {
            dsum[i]     = dsum[i - 1]           + dist[i];
            dsum[i + 1] = dsum[i - 1] + dist[i] + dist[i + 1];
        } else {
            dsum[i] = dsum[i - 1] + dist[i];
        }
    }
}
