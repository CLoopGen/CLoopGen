#include <stdio.h>

#include <inttypes.h>

typedef double FLOAT8;

extern int b;
extern FLOAT8 en[3];
extern FLOAT8 mx;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int b1, b2;
    FLOAT8 local_mx = mx;
    for (b1 = 0; b1 < 2; b1++) {
        for (b2 = 0; b2 < 2; b2++) {
            int idx = b1 * 2 + b2;
            if (idx < 3 && en[idx] > local_mx) {
                local_mx = en[idx];
            }
        }
    }
    mx = local_mx;
}
