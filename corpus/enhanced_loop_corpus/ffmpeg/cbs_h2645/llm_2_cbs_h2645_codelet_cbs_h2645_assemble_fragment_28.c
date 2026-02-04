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
    // Variant 1: Strided memory access (step by 2, then handle remainder)
    size_t stride = 2;
    int i;
    // First pass: even indices
    for (i = 0; i < frag->nb_units; i += stride) {
        max_size += 4 + frag->units[i].data_size * 3 / 2;
    }
    // Second pass: odd indices
    for (i = 1; i < frag->nb_units; i += stride) {
        max_size += 4 + frag->units[i].data_size * 3 / 2;
    }
}
