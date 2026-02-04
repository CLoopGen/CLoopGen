#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int nb_pixel;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < nb_pixel / 4; i++) {
    if (i % 2 == 0) {
        continue;
    }
}
}
