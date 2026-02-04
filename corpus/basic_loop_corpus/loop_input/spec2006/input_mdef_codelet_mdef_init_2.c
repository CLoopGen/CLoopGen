#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <inttypes.h>

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

int32 s;
mdef_t *m;

void init_vars() {
    m = (mdef_t*)calloc(1, sizeof(mdef_t));
    if (!m) return;

    m->n_sen = 50000000; // ~100MB of s3cipid_t data, sufficient for ~0.01 sec on modern CPU

    m->sen2cimap = (s3cipid_t*)calloc(m->n_sen, sizeof(s3cipid_t));
    if (!m->sen2cimap) {
        free(m);
        m = NULL;
        return;
    }

    // Initialize all sen2cimap entries to -1 as per loop semantics
    for (int32 i = 0; i < m->n_sen; i++) {
        m->sen2cimap[i] = (s3cipid_t)-1;
    }

    // Other fields initialized to minimal valid values
    m->n_ciphone = 1;
    m->n_phone = 1;
    m->n_emit_state = 1;
    m->n_ci_sen = 1;
    m->n_tmat = 1;
    m->ciphone_ht = NULL;
    m->ciphone = NULL;
    m->phone = NULL;
    m->sseq = NULL;
    m->n_sseq = 0;
    m->cd2cisen = NULL;
    m->ciphone2n_cd_sen = NULL;
    m->sil = 0;
    m->wpos_ci_lclist = NULL;
}