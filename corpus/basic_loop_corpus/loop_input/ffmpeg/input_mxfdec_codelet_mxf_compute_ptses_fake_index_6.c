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
uint8_t *flags;

void init_vars() {
    const int data_size = 1 << 20; // ~1MB to keep runtime ~0.01s

    index_table = (MXFIndexTable*)calloc(1, sizeof(MXFIndexTable));
    index_table->nb_ptses = data_size;
    index_table->ptses = (int64_t*)malloc(data_size * sizeof(int64_t));
    index_table->fake_index = (AVIndexEntry*)calloc(data_size, sizeof(AVIndexEntry));
    index_table->offsets = (int8_t*)malloc(data_size * sizeof(int8_t));
    flags = (uint8_t*)malloc(data_size * sizeof(uint8_t));

    for (int i = 0; i < data_size; i++) {
        index_table->ptses[i] = (i % 2 == 0) ? ((int64_t)9223372036854775807LL) : i;
        flags[i] = (uint8_t)(i & 0x3);
        index_table->offsets[i] = (int8_t)(i & 0xFF);
    }

    index_table->nb_segments = 1;
    index_table->segments = (MXFIndexTableSegment**)calloc(1, sizeof(MXFIndexTableSegment*));
    index_table->segments[0] = (MXFIndexTableSegment*)calloc(1, sizeof(MXFIndexTableSegment));
    index_table->segments[0]->nb_index_entries = data_size;
    index_table->segments[0]->temporal_offset_entries = (int8_t*)malloc(data_size * sizeof(int8_t));
    index_table->segments[0]->flag_entries = (int*)malloc(data_size * sizeof(int));
    index_table->segments[0]->stream_offset_entries = (uint64_t*)malloc(data_size * sizeof(uint64_t));

    for (int i = 0; i < data_size; i++) {
        index_table->segments[0]->temporal_offset_entries[i] = (int8_t)(i & 0x7F);
        index_table->segments[0]->flag_entries[i] = i & 0xFFFF;
        index_table->segments[0]->stream_offset_entries[i] = (uint64_t)i * 1000;
    }
}