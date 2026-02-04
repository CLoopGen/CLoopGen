#include <stdio.h>

#include <inttypes.h>

extern int QP;
extern int i;
extern double Qstep;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < (QP / 6) * 2; i++) {
        if (i < (QP / 6))
            Qstep *= 2;
        else
            Qstep *= 2;
    }
}
