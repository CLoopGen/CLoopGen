#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
struct Track {
    const char *name;
    int64_t duration;
    int bitrate;
    int track_id;
    int is_audio;
    int is_video;
    int width;
    int height;
    int sample_rate;
    int channels;
    int timescale;
    char codec_str[30];
    int64_t sidx_start;
    int64_t sidx_length;
};


struct Tracks {
    int nb_tracks;
    int64_t duration;
    struct Track **tracks;
    int multiple_tracks_per_file;
};


extern struct Tracks *tracks;
extern int i;
extern struct Track ***adaptation_sets;
extern int *nb_tracks;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided Memory Access Pattern
    // Instead of iterating sequentially through tracks, access every second track first, then the others.
    // This creates a strided access pattern to simulate non-sequential memory traversal.
    int stride = 2;
    for (int step = 0; step < stride; step++) {
        for (i = step; i < tracks->nb_tracks; i += stride) {
            int set_index = -1;
            if (tracks->tracks[i]->is_video)
                set_index = 0;
            else if (tracks->tracks[i]->is_audio)
                set_index = 1;
            else
                continue;
            adaptation_sets[set_index][nb_tracks[set_index]++] = tracks->tracks[i];
        }
    }
}
