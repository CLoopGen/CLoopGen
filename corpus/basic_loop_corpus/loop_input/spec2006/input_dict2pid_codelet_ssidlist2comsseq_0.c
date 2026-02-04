#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

typedef int int32;

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

typedef struct hash_entry_s {
    const char *key;
    int32 len;
    int32 val;
    struct hash_entry_s *next;
} hash_entry_t;

typedef unsigned char uint8;

typedef struct {
    hash_entry_t *table;
    int32 size;
    uint8 nocase;
} hash_table_t;

typedef struct {
    char *name;
    int32 filler;
} ciphone_t;

typedef int32 s3pid_t;

typedef s3pid_t s3ssid_t;

typedef int32 s3tmatid_t;

typedef char int8;

typedef int8 s3cipid_t;

typedef enum {
    WORD_POSN_BEGIN = 0,
    WORD_POSN_END = 1,
    WORD_POSN_SINGLE = 2,
    WORD_POSN_INTERNAL = 3,
    WORD_POSN_UNDEFINED = 4
} word_posn_t;

typedef struct {
    s3ssid_t ssid;
    s3tmatid_t tmat;
    s3cipid_t ci;
    s3cipid_t lc;
    s3cipid_t rc;
    word_posn_t wpos;
} phone_t;

typedef short int16;

typedef int16 s3senid_t;

typedef struct ph_rc_s {
    s3cipid_t rc;
    s3pid_t pid;
    struct ph_rc_s *next;
} ph_rc_t;

typedef struct ph_lc_s {
    s3cipid_t lc;
    ph_rc_t *rclist;
    struct ph_lc_s *next;
} ph_lc_t;

typedef struct {
    int32 n_ciphone;
    int32 n_phone;
    int32 n_emit_state;
    int32 n_ci_sen;
    int32 n_sen;
    int32 n_tmat;
    hash_table_t *ciphone_ht;
    ciphone_t *ciphone;
    phone_t *phone;
    s3senid_t **sseq;
    int32 n_sseq;
    s3senid_t *cd2cisen;
    s3cipid_t *sen2cimap;
    int32 *ciphone2n_cd_sen;
    s3cipid_t sil;
    ph_lc_t ***wpos_ci_lclist;
} mdef_t;

extern glist_t g;
extern mdef_t *mdef;
extern int32 i;
extern int32 j;
extern int32 s;
extern int32 ssid;
extern s3senid_t **sen;
extern gnode_t *gn;

glist_t g = NULL;
mdef_t *mdef = NULL;
int32 i = 0;
int32 j = 0;
int32 s = 0;
int32 ssid = 0;
s3senid_t **sen = NULL;
gnode_t *gn = NULL;

void init_vars() {
    const int NUM_GNODES = 500;
    const int N_EMIT_STATE = 20;
    const int SEN_LEN = 100;

    gnode_t *nodes = calloc(NUM_GNODES, sizeof(gnode_t));
    for (int idx = 0; idx < NUM_GNODES; idx++) {
        nodes[idx].data.int32 = idx % N_EMIT_STATE;
        if (idx < NUM_GNODES - 1)
            nodes[idx].next = &nodes[idx + 1];
        else
            nodes[idx].next = NULL;
    }
    g = &nodes[0];

    mdef = calloc(1, sizeof(mdef_t));
    mdef->n_emit_state = N_EMIT_STATE;
    mdef->n_sseq = N_EMIT_STATE;
    mdef->sseq = calloc(N_EMIT_STATE, sizeof(s3senid_t*));
    for (int idx = 0; idx < N_EMIT_STATE; idx++) {
        mdef->sseq[idx] = calloc(N_EMIT_STATE, sizeof(s3senid_t));
        for (int jdx = 0; jdx < N_EMIT_STATE; jdx++) {
            mdef->sseq[idx][jdx] = (idx + jdx) % 500;
        }
    }

    sen = calloc(N_EMIT_STATE, sizeof(s3senid_t*));
    for (int idx = 0; idx < N_EMIT_STATE; idx++) {
        sen[idx] = calloc(SEN_LEN, sizeof(s3senid_t));
        for (int jdx = 0; jdx < SEN_LEN - 1; jdx++) {
            sen[idx][jdx] = -1;
        }
        sen[idx][SEN_LEN - 1] = -1;
    }

    mdef->sil = 0;
}