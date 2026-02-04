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
    int *class_dims = (int*)malloc(fc->nclasses * sizeof(int));
    for (int c = 0; c < fc->nclasses; c++) {
        class_dims[c] = fc->classes[c].dim;
    }
    for (i = 0; i < fc->partitions; i++) {
        int class_idx = fc->partition_to_class[i];
        fc->values += class_dims[class_idx];
    }
    free(class_dims);
}
