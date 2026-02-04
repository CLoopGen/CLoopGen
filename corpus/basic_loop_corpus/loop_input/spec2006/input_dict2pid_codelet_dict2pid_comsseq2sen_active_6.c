#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <inttypes.h>

typedef int int32;

typedef int32 s3pid_t;

typedef s3pid_t s3ssid_t;

typedef short int16;

typedef int16 s3senid_t;

typedef struct {
    s3ssid_t **internal;
    s3ssid_t ***ldiph_lc;
    s3ssid_t **single_lc;
    s3senid_t **comstate;
    s3senid_t **comsseq;
    int32 *comwt;
    int32 n_comstate;
    int32 n_comsseq;
} dict2pid_t;

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

dict2pid_t *d2p;
mdef_t *mdef;
int32 *comssid;
int32 *sen;
int32 ss;
int32 cs;
int32 i;
int32 j;
s3senid_t *csp;
s3senid_t *sp;

void init_vars() {
    d2p = (dict2pid_t *)calloc(1, sizeof(dict2pid_t));
    mdef = (mdef_t *)calloc(1, sizeof(mdef_t));

    mdef->n_emit_state = 100;
    d2p->n_comsseq = 50000;
    d2p->n_comstate = 20000;

    comssid = (int32 *)calloc(d2p->n_comsseq, sizeof(int32));
    sen = (int32 *)calloc(1000000, sizeof(int32));

    d2p->comsseq = (s3senid_t **)calloc(d2p->n_comsseq, sizeof(s3senid_t *));
    d2p->comstate = (s3senid_t **)calloc(d2p->n_comstate, sizeof(s3senid_t *));

    for (int i = 0; i < d2p->n_comsseq; i++) {
        if (i % 2 == 0) {
            comssid[i] = 1;
            s3senid_t *row = (s3senid_t *)calloc(mdef->n_emit_state, sizeof(s3senid_t));
            for (int k = 0; k < mdef->n_emit_state; k++) {
                row[k] = rand() % d2p->n_comstate;
            }
            d2p->comsseq[i] = row;
        } else {
            comssid[i] = 0;
            d2p->comsseq[i] = NULL;
        }
    }

    for (int i = 0; i < d2p->n_comstate; i++) {
        int len = 10 + (rand() % 20);
        s3senid_t *row = (s3senid_t *)calloc(len + 1, sizeof(s3senid_t));
        for (int k = 0; k < len; k++) {
            row[k] = rand() % 1000000;
        }
        row[len] = -1;
        d2p->comstate[i] = row;
    }

    mdef->n_ciphone = 1;
    mdef->n_phone = 1;
    mdef->n_ci_sen = 1;
    mdef->n_sen = 1;
    mdef->n_tmat = 1;
    mdef->ciphone_ht = NULL;
    mdef->ciphone = NULL;
    mdef->phone = NULL;
    mdef->sseq = NULL;
    mdef->n_sseq = 0;
    mdef->cd2cisen = NULL;
    mdef->sen2cimap = NULL;
    mdef->ciphone2n_cd_sen = NULL;
    mdef->sil = 0;
    mdef->wpos_ci_lclist = NULL;
}