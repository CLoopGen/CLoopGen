#include <stdio.h>

#include <inttypes.h>

typedef double FLOAT8;

extern FLOAT8 d[32];
extern FLOAT8 *in;
extern int i;
extern FLOAT8 s;
extern FLOAT8 t;
extern FLOAT8 *wp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 15; i >= 0; --i) {
        int j, k;
        FLOAT8 s0 = s;
        FLOAT8 s1 = t * *wp++;
        for (j = 14; j >= 0; j--) {
            FLOAT8 temp1 = *wp++;
            FLOAT8 temp2 = *in++;
            for (k = 0; k < 1; k++) {  // Artificially increase nesting depth by adding a single-iteration inner loop
                s0 += temp1 * temp2;
                s1 += *wp++ * *in++;
            }
        }
        in -= 30;
        d[i] = s0 + s1;
        d[31 - i] = s0 - s1;
    }
}
