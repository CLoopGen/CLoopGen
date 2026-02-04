#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int int32;

typedef int32 s3pid_t;

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

int32 n_ci;
s3pid_t p;
int32 s;
int32 cd;
int32 ci;
mdef_t *m;

void init_vars() {
    n_ci = 1000;
    
    m = (mdef_t*)calloc(1, sizeof(mdef_t));
    m->n_phone = 5000;
    m->n_emit_state = 10;
    m->n_sseq = m->n_phone;
    
    m->sseq = (s3senid_t**)calloc(m->n_sseq, sizeof(s3senid_t*));
    for (int i = 0; i < m->n_sseq; i++) {
        m->sseq[i] = (s3senid_t*)calloc(m->n_emit_state, sizeof(s3senid_t));
        for (int j = 0; j < m->n_emit_state; j++) {
            m->sseq[i][j] = (s3senid_t)(i * m->n_emit_state + j);
        }
    }
    
    m->phone = (phone_t*)calloc(m->n_phone, sizeof(phone_t));
    for (int i = 0; i < m->n_phone; i++) {
        m->phone[i].ci = (s3cipid_t)(i % 128);
    }
    
    int total_cd = m->n_phone * m->n_emit_state;
    m->cd2cisen = (s3senid_t*)calloc(total_cd, sizeof(s3senid_t));
    m->sen2cimap = (s3cipid_t*)calloc(total_cd, sizeof(s3cipid_t));
}