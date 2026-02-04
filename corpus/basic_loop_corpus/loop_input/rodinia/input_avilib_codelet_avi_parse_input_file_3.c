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

static audio_index_entry* allocated_audio_index;
static video_index_entry* allocated_video_index;
static unsigned char (*allocated_idx_block)[16];

void init_vars() {
    allocated_audio_index = calloc(1024, sizeof(audio_index_entry));
    allocated_video_index = calloc(1024, sizeof(video_index_entry));
    allocated_idx_block = calloc(65536, 16);

    AVI = malloc(sizeof(avi_t));
    AVI->anum = 8;
    AVI->aptr = 0;
    AVI->pos = 0;
    AVI->n_idx = 0;
    AVI->max_idx = 1000;
    AVI->movi_start = 0x100000;
    AVI->must_use_index = 0;
    AVI->last_pos = 0;
    AVI->last_len = 0;
    AVI->idx = allocated_idx_block;
    AVI->video_index = allocated_video_index;

    for (int i = 0; i < 8; ++i) {
        track_t* t = &AVI->track[i];
        t->a_fmt = 1;
        t->a_chans = 2;
        t->a_rate = 44100;
        t->a_bits = 16;
        t->mp3rate = 128000;
        t->audio_strn = i + 1;
        t->audio_bytes = 1024 * 1024 * 16;
        t->audio_chunks = 0;
        t->audio_tag[0] = 'd';
        t->audio_tag[1] = 'a';
        t->audio_tag[2] = 't';
        t->audio_tag[3] = 'a';
        t->audio_posc = 0;
        t->audio_posb = 0;
        t->a_codech_off = 0;
        t->a_codecf_off = 0;
        t->audio_index = allocated_audio_index;
        nai[i] = 1000 + i * 100;
    }
}