#include <stdio.h>

#include <inttypes.h>

extern int mu;
extern int DirectLinks[8];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int mu;
    for (mu = 7; mu >= 0; mu--) {
        DirectLinks[mu] = DirectLinks[7 - mu] + 1;
    }
}
