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
    const int stride = 1;
    for (i = 0; i < nb_segments; i += stride) {
        int best = -1;
        int best_key[4] = {-1, -1, -1, -1}; // body_sid, index_sid, index_start, -index_duration (for reverse order)
        for (j = 0; j < nb_segments; j++) {
            MXFIndexTableSegment *s = unsorted_segments[j];
            int valid_condition = (i == 0) ? 1 : 
                (s->body_sid > last_body_sid) ||
                (s->body_sid == last_body_sid && s->index_sid > last_index_sid) ||
                (s->body_sid == last_body_sid && s->index_sid == last_index_sid && s->index_start_position > last_index_start);

            int current_key[4] = {s->body_sid, s->index_sid, (int)s->index_start_position, -(int)(s->index_duration & 0x7FFFFFFF)};
            int is_better = (best == -1);
            if (!is_better) {
                for (int k = 0; k < 4; k++) {
                    if (current_key[k] < best_key[k]) {
                        is_better = 1;
                        break;
                    } else if (current_key[k] > best_key[k]) {
                        break;
                    }
                }
            }
            if (valid_condition && is_better) {
                best = j;
                best_key[0] = s->body_sid;
                best_key[1] = s->index_sid;
                best_key[2] = s->index_start_position;
                best_key[3] = -(int)(s->index_duration & 0x7FFFFFFF);
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
