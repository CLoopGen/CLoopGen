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
int64_t now;

void init_vars() {
    const int approx_data_size = 128 * 1024 * 1024; // ~128MB target
    const int element_size = sizeof(struct sbg_script_tseq);
    const int nb_tseq = (approx_data_size + element_size - 1) / element_size;

    s = malloc(sizeof(struct sbg_script));
    if (!s) exit(1);

    s->tseq = calloc(nb_tseq, sizeof(struct sbg_script_tseq));
    if (!s->tseq) exit(1);

    for (int j = 0; j < nb_tseq; j++) {
        s->tseq[j].ts.t = 1000 + j * 10;
        s->tseq[j].ts.type = (j % 3 == 0) ? 'N' : 'T';
        s->tseq[j].name = NULL;
        s->tseq[j].name_len = 0;
        s->tseq[j].lock = 0;
        s->tseq[j].fade.in = 50;
        s->tseq[j].fade.out = 75;
        s->tseq[j].fade.slide = 20;
    }

    s->nb_tseq = nb_tseq;
    now = 5000000;

    i = 0;
}