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

mdef_t *mdef;
int32 cisencnt;

void init_vars() {
    const int DATA_SIZE = 1 << 20; // ~1MB of primary data

    // Allocate and initialize cd2cisen array
    s3senid_t *cd2cisen_data = (s3senid_t*)calloc(DATA_SIZE, sizeof(s3senid_t));
    for (int i = 0; i < DATA_SIZE - 1; ++i) {
        cd2cisen_data[i] = i; // ensures condition cisencnt == cd2cisen[cisencnt] holds
    }
    cd2cisen_data[DATA_SIZE - 1] = DATA_SIZE; // break condition

    // Allocate mdef structure
    mdef = (mdef_t*)malloc(sizeof(mdef_t));
    memset(mdef, 0, sizeof(mdef_t));

    mdef->n_ciphone = 100;
    mdef->n_phone = 500;
    mdef->n_emit_state = 2000;
    mdef->n_ci_sen = 300;
    mdef->n_sen = 1000;
    mdef->n_tmat = 50;
    mdef->sil = 0;
    mdef->cd2cisen = cd2cisen_data;

    // Initialize other pointers to avoid undefined behavior
    mdef->ciphone_ht = NULL;
    mdef->ciphone = NULL;
    mdef->phone = NULL;
    mdef->sseq = NULL;
    mdef->n_sseq = 0;
    mdef->sen2cimap = NULL;
    mdef->ciphone2n_cd_sen = NULL;
    mdef->wpos_ci_lclist = NULL;

    cisencnt = 0;
}