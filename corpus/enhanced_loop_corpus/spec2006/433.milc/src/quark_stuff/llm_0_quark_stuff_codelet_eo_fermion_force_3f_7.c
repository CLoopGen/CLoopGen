#include <stdio.h>

#include <inttypes.h>

extern int mu;
extern int DirectLinks[8];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int i = 0; i < 1; i++) {
        for (mu = 0; mu < 8; mu++)
            DirectLinks[mu] = 0;
    }
}
