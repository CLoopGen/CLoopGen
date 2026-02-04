#include <stdio.h>

#include <inttypes.h>

extern int mu;
extern int DirectLinks[8];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp[8];
    for (int mu = 0; mu < 8; mu++) {
        temp[mu] = mu;
    }
    for (mu = 0; mu < 8; mu++) {
        DirectLinks[mu] = temp[mu] - mu; // Introduces RAW dependency: temp[mu] must be read after write in previous loop
    }
}
