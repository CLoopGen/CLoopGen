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
    for (size_t i = 0; i < num_colors; i += 2) {
        int64_t limit1 = (i < num_colors) ? colors[i] : 0;
        int64_t limit2 = ((i + 1) < num_colors) ? colors[i + 1] : 0;
        for (int64_t j = 0; j < limit1 + limit2; ++j) {
            choices[k] = (j < limit1) ? i : i + 1;
            ++k;
        }
    }
}
