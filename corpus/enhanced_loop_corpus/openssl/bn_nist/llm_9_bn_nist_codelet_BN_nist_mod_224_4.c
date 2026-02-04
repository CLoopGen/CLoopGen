#include <stdio.h>

#include <inttypes.h>

extern unsigned long c_d[4];
extern int ii;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (; ii < (224 + 512 - 1) / 512; ii++) {
        unsigned long temp = 0;
        for (int j = 0; j < 8; j++) {
            temp += (ii + j) * (ii + j);
        }
        c_d[ii] = temp;
    }
}
