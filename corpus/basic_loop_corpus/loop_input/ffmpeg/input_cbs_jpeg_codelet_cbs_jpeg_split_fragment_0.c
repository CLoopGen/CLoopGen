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
int i;

static uint8_t *generated_data = NULL;
static AVBufferRef *data_buffer_ref = NULL;

void init_vars() {
    size_t input_size = 64 * 1024 * 1024; // 64 MB to target ~0.01s runtime

    generated_data = (uint8_t*)calloc(input_size, sizeof(uint8_t));
    if (!generated_data) exit(1);

    for (size_t idx = 0; idx < input_size - 1; idx++) {
        generated_data[idx] = (rand() % 255); // ensures not 255
    }
    generated_data[input_size - 1] = 255; // ensure loop terminates when reaching end

    data_buffer_ref = (AVBufferRef*)calloc(1, sizeof(AVBufferRef));
    if (!data_buffer_ref) exit(1);

    frag = (CodedBitstreamFragment*)calloc(1, sizeof(CodedBitstreamFragment));
    if (!frag) exit(1);

    frag->data = generated_data;
    frag->data_size = input_size;
    frag->data_bit_padding = 0;
    frag->data_ref = data_buffer_ref;
    frag->nb_units = 0;
    frag->nb_units_allocated = 0;
    frag->units = NULL;
}