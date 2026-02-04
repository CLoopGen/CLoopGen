#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double * hprev;
extern size_t * ordprev;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (i = 5 - 1; i > 0; i--) {
    hprev[i] = hprev[i - 1];
    ordprev[i] = ordprev[i - 1];
}

}
