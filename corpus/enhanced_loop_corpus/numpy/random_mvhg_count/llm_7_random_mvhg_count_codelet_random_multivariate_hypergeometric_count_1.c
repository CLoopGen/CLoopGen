#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern size_t num_colors;
extern int64_t *colors;
extern size_t *choices;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t k = 0;
    for (size_t i = 0; i < num_colors; ++i) {
        for (int64_t j = 0; j < colors[i]; ++j) {
            choices[k + j] = i;
        }
        k += colors[i];
    }
}
