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

struct Tracks *tracks;
int start_index;
int track_id;
int i;
struct Track *track;

void init_vars() {
    // Allocate and initialize MoofOffset arrays for each track
    const int offsets_per_track = 100;
    struct MoofOffset *moof_offsets[10];
    for (int j = 0; j < 10; j++) {
        moof_offsets[j] = (struct MoofOffset*)calloc(offsets_per_track, sizeof(struct MoofOffset));
        for (int k = 0; k < offsets_per_track; k++) {
            moof_offsets[j][k].time = k * 1000;
            moof_offsets[j][k].offset = k * 2000;
            moof_offsets[j][k].duration = 1000;
        }
    }

    // Allocate and initialize codec private data
    uint8_t *codec_privates[10];
    int codec_sizes[10];
    for (int j = 0; j < 10; j++) {
        codec_sizes[j] = 128;
        codec_privates[j] = (uint8_t*)malloc(codec_sizes[j]);
        for (int k = 0; k < codec_sizes[j]; k++) {
            codec_privates[j][k] = (uint8_t)(j * 31 + k * 17);
        }
    }

    // Create track names
    const char* track_names[10] = {
        "video_h264", "audio_aac", "video_vp9", "audio_mp3",
        "subtitle_1", "video_hevc", "audio_vorbis", "text_1",
        "camera_depth", "lidar_data"
    };
    
    const char* fourccs[10] = {
        "avc1", "mp4a", "vp09", "mp3 ", "tx3g",
        "hvc1", "vorb", "text", "cdep", "lida"
    };

    // Allocate and initialize individual tracks
    struct Track *individual_tracks[10];
    for (int j = 0; j < 10; j++) {
        individual_tracks[j] = (struct Track*)malloc(sizeof(struct Track));
        individual_tracks[j]->name = track_names[j];
        individual_tracks[j]->duration = 3600000 + j * 100000;
        individual_tracks[j]->bitrate = 500000 + j * 100000;
        individual_tracks[j]->track_id = j + 1;
        individual_tracks[j]->is_audio = (j % 3 == 1) ? 1 : 0;
        individual_tracks[j]->is_video = (j % 3 == 0 && j > 0) ? 1 : 0;
        individual_tracks[j]->width = (individual_tracks[j]->is_video) ? 1920 : 0;
        individual_tracks[j]->height = (individual_tracks[j]->is_video) ? 1080 : 0;
        individual_tracks[j]->chunks = offsets_per_track;
        individual_tracks[j]->sample_rate = (individual_tracks[j]->is_audio) ? 44100 : 0;
        individual_tracks[j]->channels = (individual_tracks[j]->is_audio) ? 2 : 0;
        individual_tracks[j]->codec_private = codec_privates[j];
        individual_tracks[j]->codec_private_size = codec_sizes[j];
        individual_tracks[j]->offsets = moof_offsets[j];
        individual_tracks[j]->timescale = 1000;
        individual_tracks[j]->fourcc = fourccs[j];
        individual_tracks[j]->blocksize = 1024;
        individual_tracks[j]->tag = j * 100;
    }

    // Initialize the tracks array
    tracks = (struct Tracks*)malloc(sizeof(struct Tracks));
    tracks->nb_tracks = 10;
    tracks->duration = 4000000;
    tracks->tracks = (struct Track**)malloc(tracks->nb_tracks * sizeof(struct Track*));
    for (int j = 0; j < tracks->nb_tracks; j++) {
        tracks->tracks[j] = individual_tracks[j];
    }
    tracks->video_track = 1;
    tracks->audio_track = 2;
    tracks->nb_video_tracks = 3;
    tracks->nb_audio_tracks = 3;

    // Set search parameters to find the 7th track (track_id = 7)
    start_index = 0;
    track_id = 7;
    i = 0;
    track = NULL;
}