#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int DWTELEM;

extern DWTELEM *b;
extern DWTELEM *temp;
extern  int width2;
extern int x;
extern  int w2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    DWTELEM *local_temp = temp;
    DWTELEM *local_b = b;
    int local_width2 = width2;
    int local_w2 = w2;

    for (x = 0; x < local_width2; x++) {
        DWTELEM val_even = local_b[2 * x];
        DWTELEM val_odd = local_b[2 * x + 1];

        local_temp[x] = val_even;
        local_temp[x + local_w2] = val_odd;
    }
}
