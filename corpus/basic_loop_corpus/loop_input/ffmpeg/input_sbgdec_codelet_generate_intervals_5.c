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

static struct sbg_script_synth *generated_synth = NULL;

void init_vars() {
    s = (struct sbg_script *)calloc(1, sizeof(struct sbg_script));
    if (!s) exit(1);

    const int target_size = 128 * 1024 * 1024; // Aim for ~128MB total synth data
    const int element_size = sizeof(struct sbg_script_synth);
    int nb_elements = target_size / element_size;
    if (nb_elements == 0) nb_elements = 1;

    generated_synth = (struct sbg_script_synth *)calloc(nb_elements, sizeof(struct sbg_script_synth));
    if (!generated_synth) exit(1);

    for (int j = 0; j < nb_elements; j++) {
        generated_synth[j].carrier = j * 3;
        generated_synth[j].beat = j * 7;
        generated_synth[j].vol = 100 + j % 50;
        generated_synth[j].type = SBG_TYPE_SINE;
        generated_synth[j].ref.l = -2;
        generated_synth[j].ref.r = -2;
    }

    s->synth = generated_synth;
    s->nb_synth = nb_elements;

    s->def = NULL;
    s->tseq = NULL;
    s->block_tseq = NULL;
    s->events = NULL;
    s->nb_def = 0;
    s->nb_tseq = 0;
    s->nb_events = 0;
    s->start_ts = 0;
    s->end_ts = 1000000;
    s->opt_fade_time = 10000;
    s->opt_duration = 500000;
    s->opt_mix = NULL;
    s->sample_rate = 44100;
    s->opt_start_at_first = 0;
    s->opt_end_at_last = 0;
}