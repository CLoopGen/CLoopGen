#include <stdio.h>

#include <inttypes.h>

typedef float FLOAT;

extern FLOAT cw[513];
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    FLOAT temp1 = 0.40000000000000002;
    FLOAT temp2 = temp1 * 2.5 - 0.9;
    for (j = 0; j < 513; j++) {
        cw[j] = temp1 + (temp2 - temp1) * 0.0;
    }
}
