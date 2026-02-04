#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int pc[];
extern int k;
extern int pt[51];
extern int pt_degree;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int i = 0; i <= pt_degree; i++) {
        for (int j = 0; j < 1; j++) {
            pc[i] = pt[i];
        }
    }
}
