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
int start_index;
int i;
int64_t pos;
int32_t size;

static struct Track **init_track_array(int count) {
    struct Track **track_arr = calloc(count, sizeof(struct Track*));
    for (int idx = 0; idx < count; idx++) {
        struct Track *t = malloc(sizeof(struct Track));
        t->name = "dummy_track";
        t->duration = 0;
        t->bitrate = 128000;
        t->track_id = idx + 1;
        t->is_audio = (idx % 2 == 0);
        t->is_video = (idx % 2 == 1);
        t->width = 1920;
        t->height = 1080;
        t->sample_rate = 44100;
        t->channels = 2;
        t->timescale = 1000;
        strcpy(t->codec_str, t->is_audio ? "aac" : "h264");
        t->sidx_start = 0;
        t->sidx_length = 0;
        track_arr[idx] = t;
    }
    return track_arr;
}

void init_vars() {
    const int num_tracks = 100000;
    tracks = malloc(sizeof(struct Tracks));
    tracks->nb_tracks = num_tracks;
    tracks->duration = 0;
    tracks->multiple_tracks_per_file = 1;
    tracks->tracks = init_track_array(num_tracks);

    start_index = 0;
    pos = 1000000;
    size = 50000;
}