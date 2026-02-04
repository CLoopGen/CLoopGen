#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

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

typedef struct AVIndexEntry {
    int64_t pos;
    int64_t timestamp;
    int flags : 2;
    int size : 30;
    int min_distance;
} AVIndexEntry;

typedef struct MXFIndexTable {
    int index_sid;
    int body_sid;
    int nb_ptses;
    int64_t first_dts;
    int64_t *ptses;
    int nb_segments;
    MXFIndexTableSegment **segments;
    AVIndexEntry *fake_index;
    int8_t *offsets;
} MXFIndexTable;

MXFIndexTable *index_table;
int x;

void init_vars() {
    const size_t target_size = 16 * 1024 * 1024; // Aim for ~16MB of data to achieve ~0.01s runtime
    const int approx_elements = target_size / sizeof(int64_t);
    const int num_segments = 1;

    index_table = (MXFIndexTable*)calloc(1, sizeof(MXFIndexTable));
    if (!index_table) exit(1);

    index_table->nb_ptses = approx_elements;
    index_table->ptses = (int64_t*)calloc(approx_elements, sizeof(int64_t));
    if (!index_table->ptses) exit(1);

    index_table->nb_segments = num_segments;
    index_table->segments = (MXFIndexTableSegment**)calloc(num_segments, sizeof(MXFIndexTableSegment*));
    if (!index_table->segments) exit(1);

    for (int i = 0; i < num_segments; i++) {
        index_table->segments[i] = (MXFIndexTableSegment*)calloc(1, sizeof(MXFIndexTableSegment));
        if (!index_table->segments[i]) exit(1);
        index_table->segments[i]->nb_index_entries = 0;
        index_table->segments[i]->temporal_offset_entries = NULL;
        index_table->segments[i]->flag_entries = NULL;
        index_table->segments[i]->stream_offset_entries = NULL;
    }

    index_table->fake_index = NULL;
    index_table->offsets = NULL;
    index_table->index_sid = 0;
    index_table->body_sid = 0;
    index_table->first_dts = 0;
}