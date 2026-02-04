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
static CodedBitstreamUnit *generated_units = NULL;
static AVBufferRef *generated_data_ref = NULL;

void init_vars() {
    size_t data_size = 128 * 1024 * 1024; // 128 MB to target ~0.01s runtime

    generated_data = (uint8_t *)calloc(data_size, sizeof(uint8_t));
    if (!generated_data) exit(1);

    for (size_t j = 0; j < data_size; ++j)
        generated_data[j] = 255;

    generated_data[data_size - 1] = 0; // ensure loop terminates before OOB

    generated_data_ref = (AVBufferRef *)calloc(1, sizeof(AVBufferRef));
    if (!generated_data_ref) exit(1);

    generated_units = (CodedBitstreamUnit *)calloc(1, sizeof(CodedBitstreamUnit));
    if (!generated_units) exit(1);

    frag = (CodedBitstreamFragment *)calloc(1, sizeof(CodedBitstreamFragment));
    if (!frag) exit(1);

    frag->data = generated_data;
    frag->data_size = data_size;
    frag->data_bit_padding = 0;
    frag->data_ref = generated_data_ref;
    frag->nb_units = 0;
    frag->nb_units_allocated = 1;
    frag->units = generated_units;

    i = 0;
}