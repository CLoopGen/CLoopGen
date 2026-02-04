#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *work;
extern  float *data;
extern float c;
extern float g;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int j = 0; j < 20; j++) {
        for (i = j * 2; i < j * 2 + 2; i++) {
            g += work[i] * work[i];
            c += data[i] * work[i];
        }
    }
}
