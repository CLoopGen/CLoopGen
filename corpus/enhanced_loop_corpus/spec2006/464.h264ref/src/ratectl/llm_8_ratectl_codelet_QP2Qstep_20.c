#include <stdio.h>

#include <inttypes.h>

extern int QP;
extern int i;
extern double Qstep;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int limit = QP / 6;
    for (i = 0; i < limit; i++) {
        Qstep *= 2.0;
        Qstep += 1.0;
    }
}
