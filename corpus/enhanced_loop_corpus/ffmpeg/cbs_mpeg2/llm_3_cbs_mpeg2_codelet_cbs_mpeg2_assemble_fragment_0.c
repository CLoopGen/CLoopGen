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
    // Variant 2: Indirect access via an index array to simulate irregular or reordered traversal
    int *indices = malloc(frag->nb_units * sizeof(int));
    if (!indices) return; // Handle allocation failure
    for (i = 0; i < frag->nb_units; i++)
        indices[i] = i; // Identity mapping (could be randomized or reordered in practice)

    size = 0; // Reset size for consistent behavior
    for (i = 0; i < frag->nb_units; i++) {
        int idx = indices[i]; // Indirect access using index array
        size += 3 + frag->units[idx].data_size;
    }
    free(indices);
}
