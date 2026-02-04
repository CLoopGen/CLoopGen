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

struct sbg_script *s;
int i;
int nb_rel;

void init_vars() {
    const int data_size = 131072; // ~1MB of tseq entries (each ~8 bytes), targets ~0.01 sec runtime

    s = malloc(sizeof(struct sbg_script));
    if (!s) return;

    s->tseq = calloc(data_size, sizeof(struct sbg_script_tseq));
    if (!s->tseq) {
        free(s);
        return;
    }

    for (int idx = 0; idx < data_size; idx++) {
        s->tseq[idx].ts.type = (idx % 3 == 0) ? 'N' : 'T'; // set approx 1/3 to 'N'
    }

    s->nb_tseq = data_size;
    i = 0;
    nb_rel = 0;
}

__attribute__((constructor)) void auto_init() {
    init_vars();
}