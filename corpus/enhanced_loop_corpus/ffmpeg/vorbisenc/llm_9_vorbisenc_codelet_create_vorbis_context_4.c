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
    static const int a[] = {93, 23, 372, 6, 46, 186, 750, 14, 33, 65, 130, 260, 556, 3, 10, 18, 28, 39, 55, 79, 111, 158, 220, 312, 464, 650, 850};
    int n = fc->values;
    int offset = 2;
    // Unroll by factor of 2 to increase computational intensity
    for (i = offset; i + 1 < n; i += 2) {
        fc->list[i].x = a[i - offset];
        fc->list[i + 1].x = a[i + 1 - offset];
    }
    // Handle remaining element if any
    if (i < n) {
        fc->list[i].x = a[i - offset];
    }
}
