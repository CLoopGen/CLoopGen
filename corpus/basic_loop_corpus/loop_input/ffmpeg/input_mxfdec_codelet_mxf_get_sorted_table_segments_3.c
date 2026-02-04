#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

typedef uint8_t UID[16];

enum MXFMetadataSetType {
    AnyType,
    MaterialPackage,
    SourcePackage,
    SourceClip,
    TimecodeComponent,
    PulldownComponent,
    Sequence,
    MultipleDescriptor,
    Descriptor,
    Track,
    CryptoContext,
    Preface,
    Identification,
    ContentStorage,
    SubDescriptor,
    IndexTableSegment,
    EssenceContainerData,
    EssenceGroup,
    TaggedValue,
    TapeDescriptor,
    AVCSubDescriptor
};

typedef struct AVRational {
    int num;
    int den;
} AVRational;

typedef struct MXFIndexTableSegment {
    UID uid;
    enum MXFMetadataSetType type;
    unsigned int edit_unit_byte_count;
    int index_sid;
    int body_sid;
    AVRational index_edit_rate;
    uint64_t index_start_position;
    uint64_t index_duration;
    int8_t *temporal_offset_entries;
    int *flag_entries;
    uint64_t *stream_offset_entries;
    int nb_index_entries;
} MXFIndexTableSegment;

int *nb_sorted_segments;
MXFIndexTableSegment ***sorted_segments;
int i;
int j;
int nb_segments;
MXFIndexTableSegment **unsorted_segments;
int last_body_sid;
int last_index_sid;
int last_index_start;

static void init_arrays(MXFIndexTableSegment *seg, int idx) {
    seg->type = IndexTableSegment;
    seg->edit_unit_byte_count = 1024;
    seg->index_sid = (idx * 7) % 50;
    seg->body_sid = (idx * 13) % 30;
    seg->index_edit_rate.num = 25;
    seg->index_edit_rate.den = 1;
    seg->index_start_position = (idx * 1000000) % 100000000;
    seg->index_duration = 10000 + (idx % 50000);
    seg->nb_index_entries = 100 + (idx % 200);

    seg->temporal_offset_entries = malloc(seg->nb_index_entries * sizeof(int8_t));
    seg->flag_entries = malloc(seg->nb_index_entries * sizeof(int));
    seg->stream_offset_entries = malloc(seg->nb_index_entries * sizeof(uint64_t));

    for (int k = 0; k < seg->nb_index_entries; ++k) {
        seg->temporal_offset_entries[k] = k % 127;
        seg->flag_entries[k] = k % 2;
        seg->stream_offset_entries[k] = k * 1024ULL;
    }

    for (int k = 0; k < 16; ++k)
        seg->uid[k] = (uint8_t)(idx ^ k);
}

void init_vars() {
    nb_segments = 15000;

    unsorted_segments = malloc(nb_segments * sizeof(MXFIndexTableSegment*));
    for (int idx = 0; idx < nb_segments; ++idx) {
        unsorted_segments[idx] = malloc(sizeof(MXFIndexTableSegment));
        init_arrays(unsorted_segments[idx], idx);
    }

    sorted_segments = malloc(sizeof(MXFIndexTableSegment**));
    *sorted_segments = malloc(nb_segments * sizeof(MXFIndexTableSegment*));

    nb_sorted_segments = malloc(sizeof(int));
    *nb_sorted_segments = 0;

    last_body_sid = -1;
    last_index_sid = -1;
    last_index_start = -1;
}