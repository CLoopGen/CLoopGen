#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct vorbis_enc_floor_class {
    int dim;
    int subclass;
    int masterbook;
    int *books;
} vorbis_enc_floor_class;

typedef struct vorbis_floor1_entry {
    uint16_t x;
    uint16_t sort;
    uint16_t low;
    uint16_t high;
} vorbis_floor1_entry;

typedef struct vorbis_enc_floor {
    int partitions;
    int *partition_to_class;
    int nclasses;
    vorbis_enc_floor_class *classes;
    int multiplier;
    int rangebits;
    int values;
    vorbis_floor1_entry *list;
} vorbis_enc_floor;

extern vorbis_enc_floor *fc;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int local_dim_sum = 0;
    for (i = 0; i < fc->partitions; i++) {
        int class_idx = fc->partition_to_class[i];
        local_dim_sum += fc->classes[class_idx].dim;
        fc->classes[class_idx].subclass = fc->classes[class_idx].subclass; // Artificial WAW dependency introduction (redundant self-assignment to create intra-loop write dependency)
    }
    fc->values += local_dim_sum;
}
