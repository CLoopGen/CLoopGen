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
for (i = 0; i < nb_segments; i++) {
    int best = -1;
    uint64_t best_index_duration = 0;
    for (j = 0; j < nb_segments; j++) {
        MXFIndexTableSegment *s = unsorted_segments[j];
        int valid_candidate = 0;
        if (i == 0) {
            valid_candidate = 1;
        } else {
            if (s->body_sid != last_body_sid) {
                valid_candidate = (s->body_sid > last_body_sid);
            } else if (s->index_sid != last_index_sid) {
                valid_candidate = (s->index_sid > last_index_sid);
            } else {
                valid_candidate = (s->index_start_position > last_index_start);
            }
        }

        if (!valid_candidate) {
            continue;
        }

        if (best == -1) {
            best = j;
            best_index_duration = s->index_duration;
        } else {
            MXFIndexTableSegment *current_best = unsorted_segments[best];
            if (s->body_sid < current_best->body_sid ||
                (s->body_sid == current_best->body_sid && s->index_sid < current_best->index_sid) ||
                (s->body_sid == current_best->body_sid && s->index_sid == current_best->index_sid &&
                 s->index_start_position < current_best->index_start_position) ||
                (s->body_sid == current_best->body_sid && s->index_sid == current_best->index_sid &&
                 s->index_start_position == current_best->index_start_position &&
                 s->index_duration > best_index_duration)) {
                best = j;
                best_index_duration = s->index_duration;
            }
        }
    }
    if (best == -1)
        break;
    MXFIndexTableSegment *selected = unsorted_segments[best];
    (*sorted_segments)[(*nb_sorted_segments)++] = selected;
    last_body_sid = selected->body_sid;
    last_index_sid = selected->index_sid;
    last_index_start = selected->index_start_position;
}
}
