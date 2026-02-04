#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct AVBuffer AVBuffer;

typedef struct AVBufferRef {
    AVBuffer *buffer;
    uint8_t *data;
    int size;
} AVBufferRef;

typedef uint32_t CodedBitstreamUnitType;

typedef struct CodedBitstreamUnit {
    CodedBitstreamUnitType type;
    uint8_t *data;
    size_t data_size;
    size_t data_bit_padding;
    AVBufferRef *data_ref;
    void *content;
    AVBufferRef *content_ref;
} CodedBitstreamUnit;

typedef struct CodedBitstreamFragment {
    uint8_t *data;
    size_t data_size;
    size_t data_bit_padding;
    AVBufferRef *data_ref;
    int nb_units;
    int nb_units_allocated;
    CodedBitstreamUnit *units;
} CodedBitstreamFragment;

extern CodedBitstreamFragment *frag;
extern size_t size;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t *sizes = (size_t*)malloc(frag->nb_units * sizeof(size_t));
    if (!sizes) return;
    for (int j = 0; j < frag->nb_units; j++)
        sizes[j] = frag->units[j].data_size;
    for (int j = 0; j < frag->nb_units; j++)
        size += sizes[j];
    free(sizes);
}
