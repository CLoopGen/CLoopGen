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
    int i = 0;
    int partitions = fc->partitions;
    int *pclass = fc->partition_to_class;
    vorbis_enc_floor_class *classes = fc->classes;
    int values = fc->values;

    for (; i < partitions; i += 2) {
        if (i + 1 < partitions) {
            values += classes[pclass[i]].dim + classes[pclass[i+1]].dim;
        } else {
            values += classes[pclass[i]].dim;
        }
    }

    fc->values = values;
}
