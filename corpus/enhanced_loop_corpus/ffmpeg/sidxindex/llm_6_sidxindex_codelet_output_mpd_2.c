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
    int local_nb_tracks[2] = {0}; // Local counters to eliminate WAR/WAW on nb_tracks
    for (i = 0; i < tracks->nb_tracks; i++) {
        int set_index = -1;
        if (tracks->tracks[i]->is_video) {
            set_index = 0;
        } else if (tracks->tracks[i]->is_audio) {
            set_index = 1;
        } else {
            continue;
        }
        // Remove loop-carried dependency by using local counter instead of shared global
        adaptation_sets[set_index][local_nb_tracks[set_index]++] = tracks->tracks[i];
    }
    // Update global counters after loop to preserve semantics
    nb_tracks[0] += local_nb_tracks[0];
    nb_tracks[1] += local_nb_tracks[1];
}
