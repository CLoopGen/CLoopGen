#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
struct MoofOffset {
    int64_t time;
    int64_t offset;
    int64_t duration;
};


struct Track {
    const char *name;
    int64_t duration;
    int bitrate;
    int track_id;
    int is_audio;
    int is_video;
    int width;
    int height;
    int chunks;
    int sample_rate;
    int channels;
    uint8_t *codec_private;
    int codec_private_size;
    struct MoofOffset *offsets;
    int timescale;
    const char *fourcc;
    int blocksize;
    int tag;
};


struct Tracks {
    int nb_tracks;
    int64_t duration;
    struct Track **tracks;
    int video_track;
    int audio_track;
    int nb_video_tracks;
    int nb_audio_tracks;
};


extern struct Tracks *tracks;
extern int start_index;
extern int track_id;
extern int i;
extern struct Track *track;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with pointer arithmetic
    struct Track **current = tracks->tracks + start_index;
    struct Track **end = tracks->tracks + tracks->nb_tracks;
    for (; current < end; current++) {
        if ((*current)->track_id == track_id) {
            track = *current;
            break;
        }
    }
}
