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

typedef struct VP9RawSuperframeIndex {
    uint8_t superframe_marker;
    uint8_t bytes_per_framesize_minus_1;
    uint8_t frames_in_superframe_minus_1;
    uint32_t frame_sizes[8];
} VP9RawSuperframeIndex;

CodedBitstreamFragment *frag;
VP9RawSuperframeIndex sfi;
size_t size;
int i;
int size_len;

void init_vars() {
    size_len = 4;
    size = 0;
    i = 0;

    frag = malloc(sizeof(CodedBitstreamFragment));
    frag->nb_units = 8;
    frag->nb_units_allocated = 8;
    frag->units = calloc(frag->nb_units, sizeof(CodedBitstreamUnit));

    for (int idx = 0; idx < frag->nb_units; idx++) {
        size_t unit_size = 16777216; // ~16.78 MB per unit, total ~134 MB
        uint8_t *unit_data = malloc(unit_size);
        for (size_t j = 0; j < unit_size; j++) {
            unit_data[j] = (uint8_t)(j & 0xFF);
        }
        frag->units[idx].data = unit_data;
        frag->units[idx].data_size = unit_size;
        frag->units[idx].type = idx + 1;
        frag->units[idx].data_bit_padding = 0;
        frag->units[idx].data_ref = NULL;
        frag->units[idx].content = NULL;
        frag->units[idx].content_ref = NULL;
    }

    sfi.superframe_marker = 0xc0;
    sfi.bytes_per_framesize_minus_1 = 3;
    sfi.frames_in_superframe_minus_1 = 7;
    for (int idx = 0; idx < 8; idx++) {
        sfi.frame_sizes[idx] = 0;
    }
}