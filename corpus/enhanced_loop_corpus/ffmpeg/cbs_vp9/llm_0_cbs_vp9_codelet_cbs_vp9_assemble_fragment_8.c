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
    // Variant 1: Increased loop nesting depth by splitting the original loop into two nested loops.
    // The outer loop iterates over chunks of units, and the inner loop processes each unit in the chunk.
    size = 0; // Reset size as in original context it's likely accumulated
    int chunk_size = 4;
    int num_chunks = (frag->nb_units + chunk_size - 1) / chunk_size;

    for (i = 0; i < num_chunks; i++) {
        int start = i * chunk_size;
        int end = (start + chunk_size < frag->nb_units) ? start + chunk_size : frag->nb_units;
        for (int j = start; j < end; j++) {
            size += size_len + frag->units[j].data_size;
            sfi.frame_sizes[j] = frag->units[j].data_size;
        }
    }
}
