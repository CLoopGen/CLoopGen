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
int64_t trans_time;
struct sbg_script_event *ev1;
struct sbg_script_event *ev2;
int64_t period;
int i;

#define EVENT_COUNT 50000

static struct sbg_script_event events[EVENT_COUNT];
static struct sbg_script_definition def;
static struct sbg_script_synth synth;
static struct sbg_script_tseq tseq;
static char opt_mix[32];

void init_vars() {
    s = (struct sbg_script *)malloc(sizeof(struct sbg_script));
    if (!s) exit(1);

    for (int j = 0; j < EVENT_COUNT; j++) {
        events[j].ts = j * 1000000LL;
        events[j].ts_int = j * 1000000LL + 500000LL;
        events[j].ts_trans = j * 1000000LL + 750000LL;
        events[j].ts_next = 0;
        events[j].elements = 1;
        events[j].nb_elements = 1;
        events[j].fade.in = 10;
        events[j].fade.out = 10;
        events[j].fade.slide = 0;
    }

    s->def = &def;
    s->synth = &synth;
    s->tseq = &tseq;
    s->block_tseq = NULL;
    s->events = events;
    s->nb_def = 1;
    s->nb_tseq = 1;
    s->nb_events = EVENT_COUNT;
    s->nb_synth = 1;
    s->start_ts = 0;
    s->end_ts = 100000000000LL;
    s->opt_fade_time = 5000000LL;
    s->opt_duration = 300000000LL;
    s->opt_mix = opt_mix;
    s->sample_rate = 44100;
    s->opt_start_at_first = 1;
    s->opt_end_at_last = 1;

    trans_time = 2500000LL;
    period = 1000000000LL;

    ev1 = NULL;
    ev2 = NULL;
    i = 0;
}