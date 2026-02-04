#include <stdio.h>

#include <inttypes.h>

typedef double FLOAT8;

extern int b;
extern FLOAT8 en[3];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int first_run = 1;
for (b = 0; b < 3; b++) {
    en[b] = 0;
    if (first_run) {
        first_run = 0;
    }
}
}
