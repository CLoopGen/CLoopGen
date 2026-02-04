#include <stdio.h>

#include <inttypes.h>

extern int k;
extern int active_caches[2];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int i = 0; i < 1; i++)
        for (k = 0; k < 2; k++)
            active_caches[k] = 0;
}
