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

CodedBitstreamFragment *frag;
size_t size;
int i;

void init_vars() {
    const int total_data_size = 128 * 1024 * 1024; // 128 MB total data
    const int avg_unit_size = 1024;
    const int nb_units = total_data_size / avg_unit_size;

    frag = (CodedBitstreamFragment*)calloc(1, sizeof(CodedBitstreamFragment));
    frag->units = (CodedBitstreamUnit*)calloc(nb_units, sizeof(CodedBitstreamUnit));
    frag->nb_units = nb_units;
    frag->nb_units_allocated = nb_units;

    uint8_t* global_data = (uint8_t*)malloc(total_data_size);
    size_t current_offset = 0;

    for (int idx = 0; idx < nb_units; idx++) {
        size_t unit_size = (idx < nb_units - 1) ? 
            avg_unit_size : (total_data_size - current_offset); // last unit takes remainder
        if (current_offset + unit_size > total_data_size) 
            unit_size = total_data_size - current_offset;

        frag->units[idx].data_size = unit_size;
        current_offset += unit_size;
    }

    frag->data = global_data;
    frag->data_size = total_data_size;

    size = 0;
    i = 0;
}