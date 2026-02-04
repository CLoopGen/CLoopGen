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
    int stride = 1;
    for (i = 0; i < fc->partitions; i += stride) {
        int ptc_idx = fc->partition_to_class[i];
        const vorbis_enc_floor_class *cls = &fc->classes[ptc_idx];
        fc->values += cls->dim;
        for (int j = 1; j < stride && (i + j) < fc->partitions; j++) {
            int next_ptc_idx = fc->partition_to_class[i + j];
            fc->values += fc->classes[next_ptc_idx].dim;
        }
    }
}
