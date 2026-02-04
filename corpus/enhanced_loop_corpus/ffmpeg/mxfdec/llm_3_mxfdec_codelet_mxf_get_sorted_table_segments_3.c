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

extern int *nb_sorted_segments;
extern MXFIndexTableSegment ***sorted_segments;
extern int i;
extern int j;
extern int nb_segments;
extern MXFIndexTableSegment **unsorted_segments;
extern int last_body_sid;
extern int last_index_sid;
extern int last_index_start;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Use indirect array indexing via an index permutation table to alter memory access pattern
    // Simulate precomputed access order (e.g., reverse order access without changing logic outcome)
    int *access_order = alloca(nb_segments * sizeof(int));
    for (int temp_j = 0; temp_j < nb_segments; temp_j++) {
        access_order[temp_j] = nb_segments - 1 - temp_j;  // reverse access order
    }

    for (i = 0; i < nb_segments; i++) {
        int best = -1, best_body_sid = -1, best_index_sid = -1, best_index_start = -1;
        uint64_t best_index_duration = 0;

        for (int k = 0; k < nb_segments; k++) {
            j = access_order[k];  // Indirect access through permuted index
            MXFIndexTableSegment *s = unsorted_segments[j];
            if ((i == 0 || s->body_sid > last_body_sid || (s->body_sid == last_body_sid && s->index_sid > last_index_sid) || 
                (s->body_sid == last_body_sid && s->index_sid == last_index_sid && s->index_start_position > last_index_start)) &&
                (best == -1 || s->body_sid < best_body_sid || 
                 (s->body_sid == best_body_sid && s->index_sid < best_index_sid) || 
                 (s->body_sid == best_body_sid && s->index_sid == best_index_sid && s->index_start_position < best_index_start) || 
                 (s->body_sid == best_body_sid && s->index_sid == best_index_sid && s->index_start_position == best_index_start && s->index_duration > best_index_duration))) {
                best = j;
                best_body_sid = s->body_sid;
                best_index_sid = s->index_sid;
                best_index_start = s->index_start_position;
                best_index_duration = s->index_duration;
            }
        }
        if (best == -1)
            break;
        (*sorted_segments)[(*nb_sorted_segments)++] = unsorted_segments[best];
        last_body_sid = best_body_sid;
        last_index_sid = best_index_sid;
        last_index_start = best_index_start;
    }
}
