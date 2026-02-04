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
    for (i = 0; i < tracks->nb_tracks; i++) {
        struct Track *t = tracks->tracks[i];
        int set_index;

        if (!t->is_audio && !t->is_video) {
            continue;
        }

        set_index = t->is_video ? 0 : 1;
        adaptation_sets[set_index][nb_tracks[set_index]++] = t;
    }
}
