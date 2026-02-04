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
extern size_t max;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Indirect memory access via index array (simulates gather access pattern)
    int *indices = (int*)malloc(frag->nb_units * sizeof(int));
    if (!indices) return; // Handle malloc failure
    for (int j = 0; j < frag->nb_units; j++) {
        indices[j] = j; // Populate index array (could be shuffled or reordered in real use cases)
    }
    for (i = 0; i < frag->nb_units; i++) {
        int idx = indices[i]; // Indirect access
        if (max < frag->units[idx].data_size)
            max = frag->units[idx].data_size;
    }
    free(indices);
}
