#include <stdio.h>

#include <inttypes.h>

extern int QP;
extern int i;
extern double Qstep;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j;
    for (j = 0; j < 2; j++)
        for (i = 0; i < (QP / 6); i++)
            Qstep *= 2;
}
