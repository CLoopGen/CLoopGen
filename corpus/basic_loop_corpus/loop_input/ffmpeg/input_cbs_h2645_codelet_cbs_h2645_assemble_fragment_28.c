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
size_t max_size;
int i;

static uint8_t **generated_data_blocks = NULL;
static CodedBitstreamUnit *unit_array = NULL;
static AVBufferRef **buffer_refs = NULL;

void init_vars() {
    const int target_duration_ms = 10;
    const long long typical_ops_per_unit = 100;
    const long long cpu_freq_guesstimate = 3000000000;
    const long long ops_per_sec = cpu_freq_guesstimate / typical_ops_per_unit;
    const int units_estimate = (int)(ops_per_sec * target_duration_ms / 1000000);
    const int nb_units = (units_estimate > 1000) ? units_estimate : 1000;

    frag = (CodedBitstreamFragment*)calloc(1, sizeof(CodedBitstreamFragment));
    if (!frag) exit(1);

    unit_array = (CodedBitstreamUnit*)calloc(nb_units, sizeof(CodedBitstreamUnit));
    if (!unit_array) exit(1);

    generated_data_blocks = (uint8_t**)calloc(nb_units, sizeof(uint8_t*));
    if (!generated_data_blocks) exit(1);

    buffer_refs = (AVBufferRef**)calloc(nb_units, sizeof(AVBufferRef*));
    if (!buffer_refs) exit(1);

    for (int idx = 0; idx < nb_units; idx++) {
        size_t block_size = 1000 + (idx % 15000);
        uint8_t* data_block = (uint8_t*)malloc(block_size);
        if (!data_block) exit(1);
        generated_data_blocks[idx] = data_block;

        AVBufferRef* buf_ref = (AVBufferRef*)calloc(1, sizeof(AVBufferRef));
        if (!buf_ref) exit(1);
        buf_ref->data = data_block;
        buf_ref->size = (int)block_size;
        buffer_refs[idx] = buf_ref;

        CodedBitstreamUnit* unit = &unit_array[idx];
        unit->type = 0;
        unit->data = data_block;
        unit->data_size = block_size;
        unit->data_bit_padding = 0;
        unit->data_ref = buf_ref;
        unit->content = NULL;
        unit->content_ref = NULL;
    }

    frag->nb_units = nb_units;
    frag->nb_units_allocated = nb_units;
    frag->units = unit_array;
    frag->data = NULL;
    frag->data_size = 0;
    frag->data_bit_padding = 0;
    frag->data_ref = NULL;

    max_size = 0;
    i = 0;
}