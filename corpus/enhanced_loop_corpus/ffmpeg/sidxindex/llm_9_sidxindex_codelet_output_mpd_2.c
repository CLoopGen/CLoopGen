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
    // Variant 2: Reduced trip count by processing two elements per iteration (loop unrolling)
    // This reduces loop overhead and increases stride, modifying computational characteristics
    int total_tracks = tracks->nb_tracks;
    int remainder = total_tracks % 2;

    // Process two tracks per iteration where possible
    for (i = 0; i < total_tracks - remainder; i += 2) {
        struct Track *track1 = tracks->tracks[i];
        struct Track *track2 = tracks->tracks[i + 1];

        // Handle first track
        if (track1->is_video) {
            int idx = nb_tracks[0]++;
            adaptation_sets[0][idx] = track1;
        } else if (track1->is_audio) {
            int idx = nb_tracks[1]++;
            adaptation_sets[1][idx] = track1;
        }

        // Handle second track
        if (track2->is_video) {
            int idx = nb_tracks[0]++;
            adaptation_sets[0][idx] = track2;
        } else if (track2->is_audio) {
            int idx = nb_tracks[1]++;
            adaptation_sets[1][idx] = track2;
        }
    }

    // Handle leftover element if any
    if (remainder == 1) {
        struct Track *last_track = tracks->tracks[total_tracks - 1];
        if (last_track->is_video) {
            adaptation_sets[0][nb_tracks[0]++] = last_track;
        } else if (last_track->is_audio) {
            adaptation_sets[1][nb_tracks[1]++] = last_track;
        }
    }
}
