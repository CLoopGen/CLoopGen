#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

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

static vithist_entry_t **local_entry;
static int32 *local_frame_start;
static vithist_entry_t *local_vithist_entries;
static vh_lms2vh_t **local_lms2vh_root;
static vh_lms2vh_t *local_lms2vh_entries;

void init_vars() {
    const int32 n_frm = 5000000;
    const int32 entries_per_frame = 2;

    local_vithist_entries = (vithist_entry_t*)calloc(n_frm * entries_per_frame, sizeof(vithist_entry_t));
    local_entry = (vithist_entry_t**)malloc(n_frm * entries_per_frame * sizeof(vithist_entry_t*));
    local_frame_start = (int32*)malloc((n_frm + 1) * sizeof(int32));
    local_lms2vh_root = (vh_lms2vh_t**)calloc(n_frm, sizeof(vh_lms2vh_t*));
    local_lms2vh_entries = (vh_lms2vh_t*)calloc(n_frm, sizeof(vh_lms2vh_t));

    for (int32 i = 0; i < n_frm * entries_per_frame; ++i) {
        local_entry[i] = &local_vithist_entries[i];
    }

    for (int32 i = 0; i <= n_frm; ++i) {
        local_frame_start[i] = i * entries_per_frame;
    }

    for (int32 i = 0; i < n_frm; ++i) {
        local_lms2vh_root[i] = &local_lms2vh_entries[i];
        local_lms2vh_entries[i].state = 0;
        local_lms2vh_entries[i].vhid = i;
        local_lms2vh_entries[i].ve = &local_vithist_entries[i * entries_per_frame];
        local_lms2vh_entries[i].children = NULL;
    }

    vh = (vithist_t*)malloc(sizeof(vithist_t));
    vh->entry = local_entry;
    vh->frame_start = local_frame_start;
    vh->n_entry = n_frm * entries_per_frame;
    vh->n_frm = n_frm;
    vh->bghist = 0;
    vh->wbeam = 0;
    vh->bestscore = NULL;
    vh->bestvh = NULL;
    vh->lms2vh_root = local_lms2vh_root;
    vh->lwidlist = NULL;

    f = 0;
    sv = 0;
    nsv = 0;
}