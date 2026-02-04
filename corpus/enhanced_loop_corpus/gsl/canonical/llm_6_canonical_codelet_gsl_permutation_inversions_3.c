#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
struct gsl_permutation_struct {
    size_t size;
    size_t *data;
};


typedef struct gsl_permutation_struct gsl_permutation;

extern  gsl_permutation *p;
extern size_t count;
extern size_t i;
extern size_t j;
extern  size_t size;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t temp_count = 0;
    for (i = 0; i < size - 1; i++) {
        size_t local_count = 0;
        for (j = i + 1; j < size; j++) {
            // Introduce a temporary accumulation to create WAW and WAR dependencies within the inner loop
            local_count += (p->data[i] > p->data[j]) ? 1 : 0;
        }
        // Write local result to shared count with sequential consistency
        temp_count += local_count;
    }
    count = temp_count; // Single write to output variable after loop
}
