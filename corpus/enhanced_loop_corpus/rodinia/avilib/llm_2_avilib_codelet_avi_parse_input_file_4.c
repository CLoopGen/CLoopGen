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

extern avi_t *AVI;
extern long nai[8];
extern long tot[8];
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int i;
    for (i = 0; i < AVI->anum; ++i) {
        nai[i] = 0;
        tot[i] = 0;
    }
}
