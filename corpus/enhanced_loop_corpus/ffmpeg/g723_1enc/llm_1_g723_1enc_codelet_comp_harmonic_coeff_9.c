#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int max;
extern int energy[15];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 5; i++) {
        int offset = i * 3;
        for (int k = 0; k < 3; k++) {
            int idx = offset + k;
            if (idx < 15)
                max = ((max) > (((energy[idx]) >= 0 ? (energy[idx]) : (-(energy[idx])))) ? (max) : (((energy[idx]) >= 0 ? (energy[idx]) : (-(energy[idx])))));
        }
    }
}
