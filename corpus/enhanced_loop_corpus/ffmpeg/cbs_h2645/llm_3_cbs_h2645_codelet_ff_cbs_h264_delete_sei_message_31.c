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

extern CodedBitstreamFragment *au;
extern CodedBitstreamUnit *nal;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Indirect access via an index array (simulated with direct computation)
    // Simulate an indirect addressing using reversed order access (reverse traversal as indirect pattern)
    int *indices = alloca(au->nb_units * sizeof(int));
    for (int j = 0; j < au->nb_units; j++) {
        indices[j] = au->nb_units - 1 - j; // reverse mapping
    }
    for (i = 0; i < au->nb_units; i++) {
        int idx = indices[i];
        if (&au->units[idx] == nal) {
            break;
        }
    }
    // Map physical index back to logical unit position
    i = indices[i];
}
