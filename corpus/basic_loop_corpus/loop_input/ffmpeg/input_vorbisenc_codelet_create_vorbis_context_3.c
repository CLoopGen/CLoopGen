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

void init_vars() {
    const int num_partitions = 5000000;
    const int num_classes = 100;

    fc = (vorbis_enc_floor*)calloc(1, sizeof(vorbis_enc_floor));
    fc->partitions = num_partitions;
    fc->nclasses = num_classes;
    fc->multiplier = 2;
    fc->rangebits = 8;
    fc->values = 0;

    fc->partition_to_class = (int*)malloc(num_partitions * sizeof(int));
    for (int j = 0; j < num_partitions; j++) {
        fc->partition_to_class[j] = rand() % num_classes;
    }

    fc->classes = (vorbis_enc_floor_class*)calloc(num_classes, sizeof(vorbis_enc_floor_class));
    for (int j = 0; j < num_classes; j++) {
        fc->classes[j].dim = (rand() % 10) + 1;
        fc->classes[j].subclass = rand() % 5;
        fc->classes[j].masterbook = rand() % 10;
        fc->classes[j].books = (int*)malloc((fc->classes[j].subclass > 0 ? (1 << fc->classes[j].subclass) : 0) * sizeof(int));
        for (int k = 0; k < (1 << fc->classes[j].subclass); k++) {
            fc->classes[j].books[k] = rand();
        }
    }

    fc->list = (vorbis_floor1_entry*)malloc((num_partitions * 2) * sizeof(vorbis_floor1_entry));
    for (int j = 0; j < num_partitions * 2; j++) {
        fc->list[j].x = rand() % 65535;
        fc->list[j].sort = rand() % 65535;
        fc->list[j].low = rand() % 65535;
        fc->list[j].high = rand() % 65535;
    }
}