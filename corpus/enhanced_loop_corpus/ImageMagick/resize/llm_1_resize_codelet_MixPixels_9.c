#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float MagickFloatType;

typedef MagickFloatType Quantum;

extern  Quantum *source;
extern  ssize_t *source_offset;
extern  size_t source_size;
extern Quantum *destination;
extern  ssize_t destination_offset;
extern  size_t channels;
extern ssize_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    ssize_t ij;
    const ssize_t total_ops = (ssize_t)(channels * source_size);
    ssize_t *temp_sum = (ssize_t*)calloc(channels, sizeof(ssize_t));
    
    if (!temp_sum) return;

    for (ij = 0; ij < total_ops; ij++) {
        const ssize_t i = ij % (ssize_t)channels;
        const ssize_t j = ij / (ssize_t)channels;
        if (j < (ssize_t)source_size) {
            temp_sum[i] += (ssize_t)source[source_offset[j] * (ssize_t)channels + i];
        }
    }

    for (i = 0; i < (ssize_t)channels; i++) {
        destination[(ssize_t)channels * destination_offset + i] = (Quantum)(temp_sum[i] / (ssize_t)source_size);
    }

    free(temp_sum);
}
