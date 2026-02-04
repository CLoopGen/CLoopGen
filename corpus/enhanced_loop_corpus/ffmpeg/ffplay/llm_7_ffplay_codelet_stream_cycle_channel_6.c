#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
enum AVDiscard {
    AVDISCARD_NONE = -16,
    AVDISCARD_DEFAULT = 0,
    AVDISCARD_NONREF = 8,
    AVDISCARD_BIDIR = 16,
    AVDISCARD_NONINTRA = 24,
    AVDISCARD_NONKEY = 32,
    AVDISCARD_ALL = 48
};


typedef struct AVDictionary AVDictionary;

typedef struct AVProgram {
    int id;
    int flags;
    enum AVDiscard discard;
    unsigned int *stream_index;
    unsigned int nb_stream_indexes;
    AVDictionary *metadata;
    int program_num;
    int pmt_pid;
    int pcr_pid;
    int pmt_version;
    int64_t start_time;
    int64_t end_time;
    int64_t pts_wrap_reference;
    int pts_wrap_behavior;
} AVProgram;

extern int start_index;
extern int stream_index;
extern AVProgram *p;
extern int nb_streams;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp_index = -1;
    for (int i = 0; i < nb_streams; i++) {
        // Remove direct loop-carried dependency by using a local temporary
        // Introduce RAW: read after write of p->stream_index[i]
        if (p->stream_index[i] == stream_index && temp_index == -1) {
            temp_index = i; // First match only, no overwriting (removes WAW)
        }
    }
    start_index = (temp_index == -1) ? nb_streams : temp_index;
}
