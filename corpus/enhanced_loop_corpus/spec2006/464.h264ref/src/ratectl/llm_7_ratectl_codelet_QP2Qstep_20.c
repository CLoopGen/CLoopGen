#include <stdio.h>

#include <inttypes.h>

extern int QP;
extern int i;
extern double Qstep;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double local_step = 1.0;
    for (i = 0; i < (QP / 6); i++) {
        local_step *= 2;
        Qstep = local_step; // WAW dependency introduced: multiple writes to Qstep
    }
}
