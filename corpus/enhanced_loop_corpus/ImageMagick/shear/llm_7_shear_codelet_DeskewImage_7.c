#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern size_t max_projection;
extern size_t *projection;
extern size_t width;
extern ssize_t i;
extern ssize_t skew;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    ssize_t candidate_skew = skew;
    size_t candidate_max = max_projection;
    for (i = 0; i < (ssize_t)(2 * width - 1); i += 2) {
        if (i + 1 < (ssize_t)(2 * width - 1)) {
            size_t proj_i = projection[i];
            size_t proj_i1 = projection[i + 1];
            if (proj_i > candidate_max) {
                candidate_max = proj_i;
                candidate_skew = i - (ssize_t)width + 1;
            }
            if (proj_i1 > candidate_max) {
                candidate_max = proj_i1;
                candidate_skew = i + 1 - (ssize_t)width + 1;
            }
        } else {
            if (projection[i] > candidate_max) {
                candidate_max = projection[i];
                candidate_skew = i - (ssize_t)width + 1;
            }
        }
    }
    max_projection = candidate_max;
    skew = candidate_skew;
}
