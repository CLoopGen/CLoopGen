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
    int local_nb_sorted = *nb_sorted_segments;
    int local_last_body_sid = last_body_sid;
    int local_last_index_sid = last_index_sid;
    int local_last_index_start = last_index_start;

    for (i = 0; i < nb_segments; i++) {
        int best = -1;
        int best_body_sid = -1, best_index_sid = -1, best_index_start = -1;
        uint64_t best_index_duration = 0;

        for (j = 0; j < nb_segments; j++) {
            MXFIndexTableSegment *s = unsorted_segments[j];
            int valid_candidate = 0;

            if (i == 0) {
                valid_candidate = 1;
            } else {
                valid_candidate =
                    (s->body_sid > local_last_body_sid) ||
                    (s->body_sid == local_last_body_sid && s->index_sid > local_last_index_sid) ||
                    (s->body_sid == local_last_body_sid && s->index_sid == local_last_index_sid &&
                     s->index_start_position > local_last_index_start);
            }

            int better_than_current_best = 0;
            if (best == -1) {
                better_than_current_best = 1;
            } else {
                better_than_current_best =
                    (s->body_sid < best_body_sid) ||
                    (s->body_sid == best_body_sid && s->index_sid < best_index_sid) ||
                    (s->body_sid == best_body_sid && s->index_sid == best_index_sid &&
                     s->index_start_position < best_index_start) ||
                    (s->body_sid == best_body_sid && s->index_sid == best_index_sid &&
                     s->index_start_position == best_index_start &&
                     s->index_duration > best_index_duration);
            }

            if (valid_candidate && better_than_current_best) {
                best = j;
                best_body_sid = s->body_sid;
                best_index_sid = s->index_sid;
                best_index_start = s->index_start_position;
                best_index_duration = s->index_duration;
            }
        }

        if (best == -1)
            break;

        (*sorted_segments)[local_nb_sorted++] = unsorted_segments[best];
        local_last_body_sid = best_body_sid;
        local_last_index_sid = best_index_sid;
        local_last_index_start = best_index_start;
    }

    *nb_sorted_segments = local_nb_sorted;
    last_body_sid = local_last_body_sid;
    last_index_sid = local_last_index_sid;
    last_index_start = local_last_index_start;
}
