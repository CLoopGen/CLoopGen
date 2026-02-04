#include <stdio.h>

#include <inttypes.h>

typedef double FLOAT8;

extern int b;
extern FLOAT8 en[3];
extern FLOAT8 mx;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int b;
for (b = 0; b < 3; b += 1) {
    {
        en[b] = ((en[b]) > (9.9999999999999998E-13) ? (en[b]) : (9.9999999999999998E-13)) / mx;
    }
}
}
