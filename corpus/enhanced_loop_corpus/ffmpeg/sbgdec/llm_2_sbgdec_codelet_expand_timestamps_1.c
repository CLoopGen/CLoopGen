#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
struct sbg_script_definition {
    char *name;
    int name_len;
    int elements;
    int nb_elements;
    char type;
};


enum sbg_synth_type {
    SBG_TYPE_NONE,
    SBG_TYPE_SINE,
    SBG_TYPE_NOISE,
    SBG_TYPE_BELL,
    SBG_TYPE_MIX,
    SBG_TYPE_SPIN
};


struct {
    int l;
    int r;
};


struct sbg_script_synth {
    int carrier;
    int beat;
    int vol;
    enum sbg_synth_type type;
    struct {
        int l;
        int r;
    } ref;
};


struct sbg_timestamp {
    int64_t t;
    char type;
};


struct sbg_fade {
    int8_t in;
    int8_t out;
    int8_t slide;
};


struct sbg_script_tseq {
    struct sbg_timestamp ts;
    char *name;
    int name_len;
    int lock;
    struct sbg_fade fade;
};


struct sbg_script_event {
    int64_t ts;
    int64_t ts_int;
    int64_t ts_trans;
    int64_t ts_next;
    int elements;
    int nb_elements;
    struct sbg_fade fade;
};


struct sbg_script {
    struct sbg_script_definition *def;
    struct sbg_script_synth *synth;
    struct sbg_script_tseq *tseq;
    struct sbg_script_tseq *block_tseq;
    struct sbg_script_event *events;
    int nb_def;
    int nb_tseq;
    int nb_events;
    int nb_synth;
    int64_t start_ts;
    int64_t end_ts;
    int64_t opt_fade_time;
    int64_t opt_duration;
    char *opt_mix;
    int sample_rate;
    uint8_t opt_start_at_first;
    uint8_t opt_end_at_last;
};


extern struct sbg_script *s;
extern int i;
extern int nb_rel;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided Memory Access (stride of 2)
    for (i = 0; i < s->nb_tseq; i += 2)
        nb_rel += s->tseq[i].ts.type == 'N';
}
