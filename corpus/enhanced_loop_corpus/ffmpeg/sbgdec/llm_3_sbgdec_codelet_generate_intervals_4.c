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
extern int64_t trans_time;
extern struct sbg_script_event *ev1;
extern struct sbg_script_event *ev2;
extern int64_t period;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with step size of 2, processing pairs
    int n = s->nb_events;
    // Ensure at least one iteration if nb_events is odd
    for (i = 0; i < n; i += 2) {
        int next_i = (i + 1) % n;
        int next_next_i = (i + 2) % n;

        ev1 = &s->events[i];
        ev2 = &s->events[next_i];
        struct sbg_script_event *ev1_next = &s->events[next_i];
        struct sbg_script_event *ev2_next = &s->events[next_next_i];

        if (!ev1->fade.slide) {
            ev1->ts_trans = ((ev1->ts_int) > (ev1->ts_trans - trans_time) ? (ev1->ts_int) : (ev1->ts_trans - trans_time));
            ev2->ts_int = ((ev2->ts_trans) > (ev2->ts_int + trans_time) ? (ev2->ts_int + trans_time) : (ev2->ts_trans));
        }
        ev1->ts_next = ev2->ts_int + (ev1 < ev2 ? 0 : period);

        // Process second pair if available
        if (i + 1 < n) {
            if (!ev1_next->fade.slide) {
                ev1_next->ts_trans = ((ev1_next->ts_int) > (ev1_next->ts_trans - trans_time) ? (ev1_next->ts_int) : (ev1_next->ts_trans - trans_time));
                ev2_next->ts_int = ((ev2_next->ts_trans) > (ev2_next->ts_int + trans_time) ? (ev2_next->ts_int + trans_time) : (ev2_next->ts_trans));
            }
            ev1_next->ts_next = ev2_next->ts_int + (ev1_next < ev2_next ? 0 : period);
        }
    }
}
