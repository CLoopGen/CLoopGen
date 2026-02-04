#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int pc[];
extern int k;
extern int pt_degree;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int i = 0; i <= pt_degree + 1; i++) {
        for (k = pt_degree + 1; k <= 50; k++) {
            pc[k] = 0;
        }
    }
}
