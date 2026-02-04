#include <stdio.h>

#include <inttypes.h>

extern int mu;
extern int DirectLinks[8];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (mu = 0; mu < 16; mu += 2) {
        DirectLinks[mu % 8] = mu * mu + 2 * mu + 1;
    }
}
