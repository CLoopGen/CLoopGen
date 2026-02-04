#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int int32;

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

mdef_t *mdef;
int32 *sseq;
int32 *sen;
int32 ss;
int32 i;
s3senid_t *sp;

void init_vars() {
    const int total_data_size = 64 * 1024 * 1024; // ~64MB target for performance

    mdef = (mdef_t*)calloc(1, sizeof(mdef_t));
    if (!mdef) return;

    mdef->n_sseq = 8192;
    mdef->n_emit_state = 1024;
    mdef->n_sen = 16384;

    sseq = (int32*)calloc(mdef->n_sseq, sizeof(int32));
    sen = (int32*)calloc(mdef->n_sen, sizeof(int32));

    mdef->sseq = (s3senid_t**)calloc(mdef->n_sseq, sizeof(s3senid_t*));
    if (!mdef->sseq || !sseq || !sen) return;

    for (int idx = 0; idx < mdef->n_sseq; idx++) {
        if (idx % 3 != 0) {
            sseq[idx] = 1;
            mdef->sseq[idx] = (s3senid_t*)calloc(mdef->n_emit_state, sizeof(s3senid_t));
            if (mdef->sseq[idx]) {
                for (int j = 0; j < mdef->n_emit_state; j++) {
                    mdef->sseq[idx][j] = rand() % mdef->n_sen;
                }
            }
        } else {
            sseq[idx] = 0;
            mdef->sseq[idx] = NULL;
        }
    }

    mdef->ciphone_ht = (hash_table_t*)calloc(1, sizeof(hash_table_t));
    mdef->ciphone = (ciphone_t*)calloc(1024, sizeof(ciphone_t));
    mdef->phone = (phone_t*)calloc(4096, sizeof(phone_t));
    mdef->cd2cisen = (s3senid_t*)calloc(2048, sizeof(s3senid_t));
    mdef->sen2cimap = (s3cipid_t*)calloc(mdef->n_sen, sizeof(s3cipid_t));
    mdef->ciphone2n_cd_sen = (int32*)calloc(1024, sizeof(int32));
    mdef->sil = 0;

    mdef->wpos_ci_lclist = (ph_lc_t***)calloc(5, sizeof(ph_lc_t**));
    if (mdef->wpos_ci_lclist) {
        for (int w = 0; w < 5; w++) {
            mdef->wpos_ci_lclist[w] = (ph_lc_t**)calloc(256, sizeof(ph_lc_t*));
        }
    }
}