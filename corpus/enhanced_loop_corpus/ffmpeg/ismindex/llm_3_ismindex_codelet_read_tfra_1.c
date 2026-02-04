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
    // Variant 2: Strided memory access (step by 2, then handle remainder)
    int stride = 2;
    int i;
    // First pass: strided access
    for (i = start_index; i < tracks->nb_tracks; i += stride) {
        if (tracks->tracks[i]->track_id == track_id) {
            track = tracks->tracks[i];
            return;
        }
    }
    // Second pass: check skipped elements if stride > 1
    for (i = start_index + 1; i < tracks->nb_tracks; i += stride) {
        if (tracks->tracks[i]->track_id == track_id) {
            track = tracks->tracks[i];
            return;
        }
    }
}
