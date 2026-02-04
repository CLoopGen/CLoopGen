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



void loop(){
    size_t temp_max = 0;
    int count = frag->nb_units;
    for (i = 0; i < count; i += 2) {
        size_t val1 = frag->units[i].data_size;
        if (temp_max < val1)
            temp_max = val1;
        if (i + 1 < count) {
            size_t val2 = frag->units[i + 1].data_size;
            if (temp_max < val2)
                temp_max = val2;
        }
    }
    max = temp_max;
}
