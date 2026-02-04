#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double *dp1;
extern double *dp2;
extern double s;
extern int len;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int i;
    for (i = 0; i < len; i += 2) {
        if (i + 1 < len) {
            (*dp1++) += s * (*dp2++);
            (*dp1++) += s * (*dp2++);
        } else {
            (*dp1++) += s * (*dp2++);
        }
    }
}
