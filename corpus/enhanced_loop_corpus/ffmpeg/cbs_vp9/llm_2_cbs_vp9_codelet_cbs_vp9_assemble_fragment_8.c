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

extern CodedBitstreamFragment *frag;
extern VP9RawSuperframeIndex sfi;
extern size_t size;
extern int i;
extern int size_len;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with pointer arithmetic
    CodedBitstreamUnit *unit_ptr = frag->units;
    uint32_t *frame_size_ptr = sfi.frame_sizes;
    int n = frag->nb_units;
    for (i = 0; i < n; i++) {
        size += size_len + unit_ptr->data_size;
        *frame_size_ptr++ = unit_ptr->data_size;
        unit_ptr++;
    }
}
