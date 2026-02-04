#include <stdio.h>

#include <inttypes.h>

typedef double FLOAT8;

extern int b;
extern FLOAT8 en[3];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (b = 0; b < 3; b += 2) {
        en[b] = 0.0;
        en[b] = en[b] * 2.5 + 1.0;
        if (b + 1 < 3) {
            en[b + 1] = 0.0;
            en[b + 1] = en[b + 1] * 2.5 + 1.0;
        }
    }
}
