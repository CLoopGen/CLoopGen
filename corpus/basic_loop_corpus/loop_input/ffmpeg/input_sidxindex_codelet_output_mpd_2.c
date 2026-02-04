#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

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

struct Tracks *tracks;
int i;
struct Track ***adaptation_sets;
int *nb_tracks;

void init_vars() {
    const int total_tracks = 100000;
    tracks = malloc(sizeof(struct Tracks));
    tracks->nb_tracks = total_tracks;
    tracks->duration = 3600000;
    tracks->multiple_tracks_per_file = 1;
    tracks->tracks = malloc(total_tracks * sizeof(struct Track*));

    adaptation_sets = malloc(2 * sizeof(struct Track**));
    nb_tracks = calloc(2, sizeof(int));
    adaptation_sets[0] = malloc(total_tracks * sizeof(struct Track*));
    adaptation_sets[1] = malloc(total_tracks * sizeof(struct Track*));

    for (int idx = 0; idx < total_tracks; idx++) {
        struct Track *t = malloc(sizeof(struct Track));
        t->name = "dummy_track";
        t->duration = 180000;
        t->bitrate = 128000 + (idx % 1000);
        t->track_id = idx;
        t->is_audio = (idx % 3 == 0) ? 0 : 1;
        t->is_video = !t->is_audio;
        t->width = t->is_video ? 1920 : 0;
        t->height = t->is_video ? 1080 : 0;
        t->sample_rate = t->is_audio ? 44100 : 0;
        t->channels = t->is_audio ? 2 : 0;
        t->timescale = 1000;
        snprintf(t->codec_str, sizeof(t->codec_str), "codec_%d", idx % 5);
        t->sidx_start = idx * 1000LL;
        t->sidx_length = 500;

        tracks->tracks[idx] = t;
    }
}