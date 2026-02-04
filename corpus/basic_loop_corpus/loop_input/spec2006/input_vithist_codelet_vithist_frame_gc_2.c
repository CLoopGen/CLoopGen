#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

typedef int int32;
typedef short int16;
typedef unsigned short uint16;
typedef unsigned int uint32;
typedef float float32;
typedef double float64;

typedef int32 s3wid_t;
typedef int16 s3frmid_t;
typedef uint16 s3lmwid_t;

struct {
    s3lmwid_t lwid[2];
};

union anytype_s {
    void *ptr;
    int32 int32;
    uint32 uint32;
    float32 float32;
    float64 float64;
};

typedef union anytype_s anytype_t;

typedef struct gnode_s {
    anytype_t data;
    struct gnode_s *next;
} gnode_t;

typedef gnode_t *glist_t;

union {
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
    union {
        struct {
            s3lmwid_t lwid[2];
        } lm3g;
    } lmstate;
} vithist_entry_t;

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
vithist_entry_t *ve;
vithist_entry_t *tve;
int32 se;
int32 fe;
int32 te;
int32 bs;
int32 bv;
int32 i;

static vithist_entry_t** alloc_entry_array(int32 total_entries, int32 block_size) {
    int32 num_blocks = (total_entries + block_size - 1) / block_size;
    vithist_entry_t** entry = (vithist_entry_t**)calloc(num_blocks, sizeof(vithist_entry_t*));
    for (int32 idx = 0; idx < num_blocks; ++idx) {
        entry[idx] = (vithist_entry_t*)calloc(block_size, sizeof(vithist_entry_t));
    }
    return entry;
}

static vh_lms2vh_t** alloc_lms2vh_array(int32 size) {
    vh_lms2vh_t** arr = (vh_lms2vh_t**)calloc(size, sizeof(vh_lms2vh_t*));
    for (int32 idx = 0; idx < size; ++idx) {
        arr[idx] = (vh_lms2vh_t*)calloc(1, sizeof(vh_lms2vh_t));
    }
    return arr;
}

void init_vars() {
    const int32 BLOCK_SIZE = 16384;
    const int32 TOTAL_ENTRIES = 131072;
    const int32 N_FRM = 8;
    const int32 LMS2VH_SIZE = 512;

    vh = (vithist_t*)calloc(1, sizeof(vithist_t));
    vh->entry = alloc_entry_array(TOTAL_ENTRIES, BLOCK_SIZE);
    vh->frame_start = (int32*)calloc(N_FRM + 1, sizeof(int32));
    for (int32 f = 0; f <= N_FRM; ++f) {
        vh->frame_start[f] = f * (TOTAL_ENTRIES / N_FRM);
    }
    vh->n_entry = TOTAL_ENTRIES;
    vh->n_frm = N_FRM;
    vh->bghist = 0;
    vh->wbeam = 1000;
    vh->bestscore = (int32*)calloc(N_FRM, sizeof(int32));
    vh->bestvh = (int32*)calloc(N_FRM, sizeof(int32));
    vh->lms2vh_root = alloc_lms2vh_array(LMS2VH_SIZE);
    vh->lwidlist = NULL;

    for (int32 frm = 0; frm < N_FRM; ++frm) {
        int32 start_idx = vh->frame_start[frm];
        int32 end_idx = vh->frame_start[frm + 1];
        for (int32 idx = start_idx; idx < end_idx; ++idx) {
            int32 block = idx >> 14;
            int32 offset = idx & 16383;
            if (block >= TOTAL_ENTRIES / BLOCK_SIZE) continue;
            vithist_entry_t* ent = &(vh->entry[block][offset]);
            ent->valid = (rand() % 3 != 0) ? 1 : 0;
            ent->score = rand() % 5000 - 2500;
            ent->wid = idx % 1000;
            ent->sf = frm;
            ent->ef = frm + 1;
            ent->ascr = rand() % 1000;
            ent->lscr = rand() % 1000;
            ent->pred = (idx > 0) ? idx - 1 : -1;
            ent->type = rand() % 4;
        }
    }

    ve = NULL;
    tve = NULL;
    se = vh->frame_start[2];
    fe = vh->frame_start[4] - 1;
    te = vh->frame_start[5];
    bs = -1000000;
    bv = -1;
    i = 0;
}