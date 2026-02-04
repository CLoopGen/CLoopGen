#include <stdio.h>

#include <inttypes.h>

typedef double FLOAT8;

extern int b;
extern FLOAT8 en[3];
extern FLOAT8 mx;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int i;
    FLOAT8 temp_max = mx;
    for (i = 0; i < 3; i++) {
        if (en[i] > temp_max) {
            temp_max = en[i];
        }
    }
    mx = temp_max;
}
