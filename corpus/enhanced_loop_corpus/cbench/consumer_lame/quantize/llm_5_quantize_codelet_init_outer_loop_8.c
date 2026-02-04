#include <stdio.h>

#include <inttypes.h>

typedef double FLOAT8;

extern int b;
extern FLOAT8 en[3];
extern FLOAT8 mx;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    mx = en[0];
    for (b = 1; b < 3; b++) {
        if (en[b] > mx) {
            mx = en[b];
        }
    }
}
