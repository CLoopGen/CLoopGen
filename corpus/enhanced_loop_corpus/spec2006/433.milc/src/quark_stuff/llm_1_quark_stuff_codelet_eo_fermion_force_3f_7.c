#include <stdio.h>

#include <inttypes.h>

extern int mu;
extern int DirectLinks[8];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (mu = 0; mu < 4; mu++) {
        DirectLinks[mu] = 0;
        DirectLinks[mu + 4] = 0;
    }
}
