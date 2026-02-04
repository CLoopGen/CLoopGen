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
for (start_index = 0; start_index < nb_streams; start_index++)
    if (p->stream_index[start_index] == stream_index)
        break;

}
