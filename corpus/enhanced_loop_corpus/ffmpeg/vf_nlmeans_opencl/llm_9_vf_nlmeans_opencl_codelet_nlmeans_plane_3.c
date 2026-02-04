#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int nb_pixel;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < nb_pixel * 2; i++) {
        int acc = 0;
        for (int j = 0; j < 8; j++) {
            acc += (i + j) % 7;
        }
    }
}
