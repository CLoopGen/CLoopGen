#include <stdio.h>

#include <inttypes.h>

extern int i;
extern double tmp;
extern double value;
extern double cof[11];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double local_cof[11];
    for (i = 0; i <= 10; i++) {
        local_cof[i] = cof[10 - i];
    }
    double running_tmp = tmp - 10.0;
    for (i = 0; i <= 10; i++) {
        value += local_cof[i] / running_tmp;
        running_tmp += 1.0;
    }
}
