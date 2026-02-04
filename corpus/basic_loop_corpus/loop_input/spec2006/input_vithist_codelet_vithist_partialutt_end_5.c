#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef int int32;
typedef int32 s3wid_t;
typedef short int16;
typedef int16 s3frmid_t;
typedef unsigned short uint16;
typedef uint16 s3lmwid_t;

struct {
    s3lmwid_t lwid[2];
};

typedef union {
    struct {
        s3lmwid_t lwid[2];
    } lm3g;
} vh_lmstate_t;

typedef struct {
    s3wid_t wid;
    s3frmid_t sf;
    s3frmid_t ef;
    int32 ascr;
    int32 lscr;
    int32 score;
    int32 pred;
    int32 type;
    int32 valid;
    vh_lmstate_t lmstate;
} vithist_entry_t;

typedef unsigned int uint32;
typedef float float32;
typedef double float64;

typedef union anytype_s {
    void *ptr;
    int32 int32;
    uint32 uint32;
    float32 float32;
    float64 float64;
} anytype_t;

typedef struct gnode_s {
    anytype_t data;
    struct gnode_s *next;
} gnode_t;

typedef gnode_t *glist_t;

typedef struct {
    int32 state;
    int32 vhid;
    vithist_entry_t *ve;
    glist_t children;
} vh_lms2vh_t;

typedef struct {
    vithist_entry_t **entry;
    int32 *frame_start;
    int32 n_entry;
    int32 n_frm;
    int32 bghist;
    int32 wbeam;
    int32 *bestscore;
    int32 *bestvh;
    vh_lms2vh_t **lms2vh_root;
    glist_t lwidlist;
} vithist_t;

vithist_t *vh;
int32 f;
int32 sv;
int32 nsv;

void init_vars() {
    const int32 target_size = 128 * 1024 * 1024; // Aim for ~128MB
    vh = (vithist_t*)calloc(1, sizeof(vithist_t));
    if (!vh) exit(1);

    vh->n_frm = (target_size / (sizeof(vithist_entry_t*) + sizeof(int32))) / 2;
    if (vh->n_frm < 2) vh->n_frm = 2;

    vh->entry = (vithist_entry_t**)calloc(vh->n_frm + 1, sizeof(vithist_entry_t*));
    vh->frame_start = (int32*)calloc(vh->n_frm + 1, sizeof(int32));
    vh->bestscore = (int32*)calloc(vh->n_frm, sizeof(int32));
    vh->bestvh = (int32*)calloc(vh->n_frm, sizeof(int32));
    vh->lms2vh_root = (vh_lms2vh_t**)calloc(vh->n_frm, sizeof(vh_lms2vh_t*));

    if (!vh->entry || !vh->frame_start || !vh->bestscore || !vh->bestvh || !vh->lms2vh_root)
        exit(1);

    int total_entries = 0;
    for (int i = 0; i <= vh->n_frm; ++i) {
        vh->frame_start[i] = total_entries;
        total_entries += (i % 7 == 0) ? 0 : (1 + (i * 73) % 100);
    }
    vh->n_entry = total_entries;

    vithist_entry_t *all_entries = (vithist_entry_t*)calloc(total_entries, sizeof(vithist_entry_t));
    if (!all_entries) exit(1);

    for (int i = 0; i < total_entries; ++i) {
        all_entries[i].wid = i % 1000;
        all_entries[i].sf = (i % 100) / 10;
        all_entries[i].ef = (i % 100) % 10;
        all_entries[i].ascr = -(i % 5000);
        all_entries[i].lscr = -(i % 4000);
        all_entries[i].score = -(i % 9000);
        all_entries[i].pred = (i > 0) ? (rand() % i) : -1;
        all_entries[i].type = i % 4;
        all_entries[i].valid = 1;
        all_entries[i].lmstate.lm3g.lwid[0] = i % 65535;
        all_entries[i].lmstate.lm3g.lwid[1] = (i * 31) % 65535;
    }

    for (int i = 0; i < vh->n_frm; ++i) {
        int start_idx = vh->frame_start[i];
        int next_idx = vh->frame_start[i+1];
        if (start_idx < next_idx) {
            vh->entry[i] = &all_entries[start_idx];
        } else {
            vh->entry[i] = NULL;
        }
    }

    vh->bghist = 10;
    vh->wbeam = 200;
    vh->lwidlist = NULL;

    for (int i = 0; i < vh->n_frm; ++i) {
        vh_lms2vh_t *node = (vh_lms2vh_t*)calloc(1, sizeof(vh_lms2vh_t));
        if (!node) exit(1);
        node->state = i % 5;
        node->vhid = i;
        node->ve = (vh->frame_start[i] < vh->frame_start[i+1]) ? &all_entries[vh->frame_start[i]] : NULL;
        node->children = NULL;
        vh->lms2vh_root[i] = node;
    }
}

__attribute__((constructor))
static void constructor_init() {
    init_vars();
}