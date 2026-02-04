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
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index array (simulated via pointer arithmetic)
    // Simulate indirect access by creating a virtual stride or reordered access pattern
    // Here we simulate accessing elements in reverse order up to a limit
    int start = (frag->data_size > 1024) ? frag->data_size - 1024 : 0; // Limit lookback window
    int end = frag->data_size - 1;
    i = end;

    // Traverse backwards using reverse strided access (stride = 3)
    for (; i >= start && i + 1 < frag->data_size; i -= 3) {
        if (frag->data[i] == 255) {
            // Found at i; now adjust forward to return first occurrence
            for (i = (i > 0) ? i - 2 : 0; i < frag->data_size && frag->data[i] != 255; i++)
                ;
            return;
        }
    }

    // Final fallback: complete linear scan from start if no match in strided reverse pass
    for (i = 0; i + 1 < frag->data_size && frag->data[i] != 255; i++)
        ;
}
