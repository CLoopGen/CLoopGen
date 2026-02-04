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
long nai[8];
int j;

void init_vars() {
    AVI = (avi_t*)calloc(1, sizeof(avi_t));
    if (!AVI) return;

    AVI->anum = 8;
    AVI->aptr = 0;
    AVI->fdes = -1;
    AVI->mode = 0;
    AVI->width = 1920;
    AVI->height = 1080;
    AVI->fps = 30.0;
    AVI->video_strn = 1;
    AVI->video_frames = 90000;
    AVI->video_pos = 0;
    AVI->max_len = 16000;
    AVI->pos = 0;
    AVI->n_idx = 0;
    AVI->max_idx = 1000;
    AVI->v_codech_off = 0;
    AVI->v_codecf_off = 0;
    AVI->last_pos = 0;
    AVI->last_len = 0;
    AVI->must_use_index = 0;
    AVI->movi_start = 0x10000;

    for (int i = 0; i < 8; ++i) {
        AVI->track[i].a_fmt = 1;
        AVI->track[i].a_chans = 2;
        AVI->track[i].a_rate = 44100;
        AVI->track[i].a_bits = 16;
        AVI->track[i].mp3rate = 128000;
        AVI->track[i].audio_strn = i + 1;
        AVI->track[i].audio_bytes = 0;
        AVI->track[i].audio_chunks = 0;
        AVI->track[i].audio_tag[0] = 'a';
        AVI->track[i].audio_tag[1] = 'd';
        AVI->track[i].audio_tag[2] = 'u';
        AVI->track[i].audio_tag[3] = '\0';
        AVI->track[i].audio_posc = 0;
        AVI->track[i].audio_posb = 0;
        AVI->track[i].a_codech_off = 0;
        AVI->track[i].a_codecf_off = 0;
        AVI->track[i].audio_index = NULL;
    }

    size_t idx_size = 1000;
    AVI->idx = (unsigned char(*)[16])calloc(idx_size, 16);
    if (AVI->idx) {
        for (size_t i = 0; i < idx_size; ++i) {
            for (int j = 0; j < 16; ++j) {
                AVI->idx[i][j] = (unsigned char)(i * 16 + j);
            }
        }
    }

    size_t video_idx_size = 90000;
    AVI->video_index = (video_index_entry*)calloc(video_idx_size, sizeof(video_index_entry));
    if (AVI->video_index) {
        for (size_t i = 0; i < video_idx_size; ++i) {
            AVI->video_index[i].key = i;
            AVI->video_index[i].pos = (unsigned long)(0x20000 + i * 1600);
            AVI->video_index[i].len = 1600;
        }
    }

    for (int i = 0; i < 8; ++i) {
        size_t audio_idx_size = 10000 + i * 500;
        AVI->track[i].audio_index = (audio_index_entry*)calloc(audio_idx_size, sizeof(audio_index_entry));
        if (AVI->track[i].audio_index) {
            for (size_t j = 0; j < audio_idx_size; ++j) {
                AVI->track[i].audio_index[j].pos = (unsigned long)(0x100000 + j * 1024);
                AVI->track[i].audio_index[j].len = 1024;
                AVI->track[i].audio_index[j].tot = (unsigned long)(j * 1024);
            }
            AVI->track[i].audio_chunks = (long)audio_idx_size;
            AVI->track[i].audio_bytes = (long)(audio_idx_size * 1024);
        }
    }

    for (int i = 0; i < 8; ++i) {
        nai[i] = 0;
    }

    j = 0;
}