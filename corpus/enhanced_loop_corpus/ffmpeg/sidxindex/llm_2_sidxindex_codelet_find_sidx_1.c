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
extern int start_index;
extern int i;
extern int64_t pos;
extern int32_t size;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = start_index; i < tracks->nb_tracks; i++) {
    struct Track *track = *(tracks->tracks + i);
    if (!(*(int64_t*)((char*)track + offsetof(struct Track, sidx_start)))) {
        *(int64_t*)((char*)track + offsetof(struct Track, sidx_start)) = pos;
        *(int64_t*)((char*)track + offsetof(struct Track, sidx_length)) = size;
    } else if (pos == *(int64_t*)((char*)track + offsetof(struct Track, sidx_start)) + 
                    *(int64_t*)((char*)track + offsetof(struct Track, sidx_length))) {
        *(int64_t*)((char*)track + offsetof(struct Track, sidx_length)) = pos + size - 
                    *(int64_t*)((char*)track + offsetof(struct Track, sidx_start));
    }
}
}
