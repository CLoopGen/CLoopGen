#include <stdio.h>

#include <inttypes.h>

extern int mu;
extern int DirectLinks[8];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (mu = 0; mu < 2; mu++) {
        for (int inner = 0; inner < 4; inner++) {
            DirectLinks[mu * 4 + inner] = 0;
        }
    }
}
