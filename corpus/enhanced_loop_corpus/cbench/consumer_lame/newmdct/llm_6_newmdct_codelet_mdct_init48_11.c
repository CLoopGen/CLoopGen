#include <stdio.h>

#include <inttypes.h>

typedef double FLOAT8;

extern int k;
extern FLOAT8 max;
extern FLOAT8 *wp;
extern FLOAT8 *wr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp_k;
    FLOAT8 local_max = max;
    FLOAT8 *local_wp = wp;
    FLOAT8 *local_wr = wr;
    for (temp_k = 0; temp_k < 7; temp_k++) {
        local_wr[temp_k] = local_wp[temp_k] / local_max;
    }
    wr += 7;
    wp += 7;
}
