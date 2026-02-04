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
extern size_t max_size;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Indirect access via index mapping array (simulated with simple remapping)
    int *indices = alloca(frag->nb_units * sizeof(int));
    // Create reversed access pattern
    for (int j = 0; j < frag->nb_units; j++) {
        indices[j] = frag->nb_units - 1 - j;
    }
    size_t temp_max_size = 0;
    for (int j = 0; j < frag->nb_units; j++) {
        int idx = indices[j];
        temp_max_size += 4 + frag->units[idx].data_size * 3 / 2;
    }
    max_size += temp_max_size;
}
