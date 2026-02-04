#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct {
    unsigned long pos;
    unsigned long len;
    unsigned long tot;
} audio_index_entry;

typedef struct track_s {
    long a_fmt;
    long a_chans;
    long a_rate;
    long a_bits;
    long mp3rate;
    long audio_strn;
    long audio_bytes;
    long audio_chunks;
    char audio_tag[4];
    long audio_posc;
    long audio_posb;
    long a_codech_off;
    long a_codecf_off;
    audio_index_entry *audio_index;
} track_t;

typedef struct {
    unsigned long key;
    unsigned long pos;
    unsigned long len;
} video_index_entry;

typedef struct {
    long fdes;
    long mode;
    long width;
    long height;
    double fps;
    char compressor[8];
    char compressor2[8];
    long video_strn;
    long video_frames;
    char video_tag[4];
    long video_pos;
    unsigned long max_len;
    track_t track[8];
    unsigned long pos;
    long n_idx;
    long max_idx;
    long v_codech_off;
    long v_codecf_off;
    unsigned char (*idx)[16];
    video_index_entry *video_index;
    unsigned long last_pos;
    unsigned long last_len;
    int must_use_index;
    unsigned long movi_start;
    int anum;
    int aptr;
} avi_t;

avi_t *AVI;
int j;

void init_vars() {
    AVI = (avi_t*)calloc(1, sizeof(avi_t));
    if (!AVI) return;

    AVI->anum = 8;
    AVI->aptr = 0;
    AVI->movi_start = 0x100000;
    AVI->must_use_index = 0;
    AVI->last_pos = 0;
    AVI->last_len = 0;
    AVI->n_idx = 0;
    AVI->max_idx = 1000;
    AVI->pos = 0;
    AVI->max_len = 0;
    AVI->fdes = -1;
    AVI->mode = 0;
    AVI->width = 640;
    AVI->height = 480;
    AVI->fps = 30.0;
    AVI->video_strn = 1;
    AVI->video_frames = 0;
    AVI->video_pos = 0;
    AVI->v_codech_off = 0;
    AVI->v_codecf_off = 0;
    AVI->video_tag[0] = '0';
    AVI->video_tag[1] = '0';
    AVI->video_tag[2] = 'd';
    AVI->video_tag[3] = 'c';
    AVI->compressor[0] = 'D';
    AVI->compressor[1] = 'I';
    AVI->compressor[2] = 'V';
    AVI->compressor[3] = 'X';
    AVI->compressor[4] = '\0';
    AVI->compressor2[0] = 'D';
    AVI->compressor2[1] = 'I';
    AVI->compressor2[2] = 'V';
    AVI->compressor2[3] = 'X';
    AVI->compressor2[4] = '\0';

    size_t total_audio_data_size = 128 * 1024 * 1024; // ~128 MB for audio index data
    size_t entries_per_track = total_audio_data_size / (8 * sizeof(audio_index_entry)) + 1;

    for (int i = 0; i < 8; ++i) {
        track_t* t = &AVI->track[i];
        t->a_fmt = 1;
        t->a_chans = 2;
        t->a_rate = 44100;
        t->a_bits = 16;
        t->mp3rate = 0;
        t->audio_strn = i + 1;
        t->audio_bytes = 0;
        t->audio_chunks = 0;
        t->audio_tag[0] = '0';
        t->audio_tag[1] = '0';
        t->audio_tag[2] = 'w';
        t->audio_tag[3] = 'b';
        t->audio_posc = 0;
        t->audio_posb = 0;
        t->a_codech_off = 0;
        t->a_codecf_off = 0;

        t->audio_index = (audio_index_entry*)calloc(entries_per_track, sizeof(audio_index_entry));
        if (t->audio_index) {
            for (size_t j = 0; j < entries_per_track; ++j) {
                t->audio_index[j].pos = j * 1024;
                t->audio_index[j].len = 1024;
                t->audio_index[j].tot = j * 1024 + 1024;
            }
        }
    }

    AVI->idx = (unsigned char(*)[16])calloc(AVI->max_idx, sizeof(unsigned char) * 16);
    if (AVI->idx) {
        for (int i = 0; i < AVI->max_idx; ++i) {
            for (int k = 0; k < 16; ++k) {
                AVI->idx[i][k] = (unsigned char)((i + k) % 256);
            }
        }
    }

    AVI->video_index = (video_index_entry*)calloc(AVI->max_idx, sizeof(video_index_entry));
    if (AVI->video_index) {
        for (int i = 0; i < AVI->max_idx; ++i) {
            AVI->video_index[i].key = i;
            AVI->video_index[i].pos = i * 2048;
            AVI->video_index[i].len = 2048;
        }
    }
}