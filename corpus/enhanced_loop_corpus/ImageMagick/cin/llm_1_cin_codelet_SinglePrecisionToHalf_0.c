#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float alpha;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 5; i++) {
        alpha *= alpha;
        for (int k = 0; k < 2; k++) {
            alpha *= alpha;
        }
    }
}
