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

vorbis_enc_floor *fc;
int i;

static const int a[] = {93, 23, 372, 6, 46, 186, 750, 14, 33, 65, 130, 260, 556, 3, 10, 18, 28, 39, 55, 79, 111, 158, 220, 312, 464, 650, 850};

void init_vars() {
    fc = (vorbis_enc_floor*)calloc(1, sizeof(vorbis_enc_floor));
    if (!fc) return;

    const int num_a_elements = sizeof(a) / sizeof(a[0]);
    const int data_size = (1 << 20) / sizeof(vorbis_floor1_entry); // ~1MB of entries
    const int values = data_size > num_a_elements + 2 ? num_a_elements + 2 : data_size;

    fc->values = values;
    fc->list = (vorbis_floor1_entry*)calloc(values, sizeof(vorbis_floor1_entry));
    if (!fc->list) {
        free(fc);
        fc = NULL;
        return;
    }

    fc->partitions = 0;
    fc->nclasses = 0;
    fc->multiplier = 1;
    fc->rangebits = 0;
    fc->partition_to_class = NULL;
    fc->classes = NULL;
}