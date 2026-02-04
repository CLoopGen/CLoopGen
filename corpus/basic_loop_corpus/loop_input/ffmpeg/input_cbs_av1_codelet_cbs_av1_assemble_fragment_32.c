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

static AVBufferRef **data_refs;
static uint8_t **unit_datas;
static CodedBitstreamUnit *units_array;

void init_vars() {
    const int total_data_size = 64 * 1024 * 1024; // ~64MB to target ~0.01s processing
    const int num_units = 16000;

    // Allocate fragment
    frag = (CodedBitstreamFragment*)calloc(1, sizeof(CodedBitstreamFragment));
    if (!frag) exit(1);

    // Allocate global size accumulator
    size = 0;

    // Allocate arrays for unit storage
    units_array = (CodedBitstreamUnit*)calloc(num_units, sizeof(CodedBitstreamUnit));
    if (!units_array) exit(1);

    data_refs = (AVBufferRef**)calloc(num_units, sizeof(AVBufferRef*));
    if (!data_refs) exit(1);

    unit_datas = (uint8_t**)calloc(num_units, sizeof(uint8_t*));
    if (!unit_datas) exit(1);

    size_t accumulated_size = 0;
    for (int idx = 0; idx < num_units; idx++) {
        // Distribute data roughly evenly
        size_t unit_size = (idx == num_units - 1) ?
            (total_data_size - accumulated_size) :
            (total_data_size / num_units);
        if (unit_size > (total_data_size - accumulated_size))
            unit_size = total_data_size - accumulated_size;

        uint8_t *data_ptr = (uint8_t*)malloc(unit_size);
        if (!data_ptr) exit(1);
        unit_datas[idx] = data_ptr;

        AVBufferRef *ref = (AVBufferRef*)calloc(1, sizeof(AVBufferRef));
        if (!ref) exit(1);
        ref->data = data_ptr;
        ref->size = (int)unit_size;
        data_refs[idx] = ref;

        CodedBitstreamUnit *unit = &units_array[idx];
        unit->type = 0;
        unit->data = data_ptr;
        unit->data_size = unit_size;
        unit->data_bit_padding = 0;
        unit->data_ref = ref;
        unit->content = NULL;
        unit->content_ref = NULL;

        accumulated_size += unit_size;
        if (accumulated_size >= total_data_size) break;
    }

    frag->units = units_array;
    frag->nb_units = num_units;
    frag->nb_units_allocated = num_units;
    frag->data = NULL;
    frag->data_size = 0;
    frag->data_bit_padding = 0;
    frag->data_ref = NULL;
}