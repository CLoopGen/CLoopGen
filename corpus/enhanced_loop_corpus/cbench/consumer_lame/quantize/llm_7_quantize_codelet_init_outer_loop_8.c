#include <stdio.h>

#include <inttypes.h>

typedef double FLOAT8;

extern int b;
extern FLOAT8 en[3];
extern FLOAT8 mx;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    FLOAT8 local_en[3];
    for (b = 0; b < 3; b++) {
        local_en[b] = en[b];
    }
    mx = local_en[0];
    for (b = 1; b < 3; b++) {
        if (local_en[b] > mx) {
            mx = local_en[b];
        }
    }
}
