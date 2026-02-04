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

int start_index;
int stream_index;
AVProgram *p;
int nb_streams;

static unsigned int *allocated_stream_index;

void init_vars() {
    nb_streams = 65536 * 4; // ~262KB of data, adjust to reach ~0.01s runtime
    stream_index = nb_streams - 1; // worst-case: match at last element

    allocated_stream_index = malloc(nb_streams * sizeof(unsigned int));
    if (!allocated_stream_index) {
        nb_streams = 0;
        return;
    }

    for (int i = 0; i < nb_streams; i++) {
        allocated_stream_index[i] = i; // ensure match at the end
    }

    p = malloc(sizeof(AVProgram));
    if (!p) {
        free(allocated_stream_index);
        allocated_stream_index = NULL;
        nb_streams = 0;
        return;
    }

    p->stream_index = allocated_stream_index;
    p->nb_stream_indexes = nb_streams;
}

void cleanup_vars() {
    free(allocated_stream_index);
    free(p);
}