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
    size_t local_size = 0;
    int limit = frag->nb_units;
    for (i = 0; i < limit; i++) {
        uint8_t *ptr = frag->units[i].data;
        size_t unit_size = frag->units[i].data_size;
        if (ptr != NULL && unit_size > 0) {
            local_size += unit_size + (unit_size % 2); // Artificially increase computation per iteration
        }
    }
    size = local_size;
}
