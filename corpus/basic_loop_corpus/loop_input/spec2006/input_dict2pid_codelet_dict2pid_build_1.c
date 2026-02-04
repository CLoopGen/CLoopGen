#include <stdio.h>
#include <stdlib.h>
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

mdef_t *mdef;
dict2pid_t *dict2pid;
s3ssid_t **ldiph;
s3ssid_t **rdiph;
s3ssid_t *single;
int32 b;
int32 l;
int32 r;

void init_vars() {
    mdef = (mdef_t *)calloc(1, sizeof(mdef_t));
    dict2pid = (dict2pid_t *)calloc(1, sizeof(dict2pid_t));

    mdef->n_ciphone = 128;

    int32 n = mdef->n_ciphone;

    ldiph = (s3ssid_t **)calloc(n, sizeof(s3ssid_t *));
    for (int i = 0; i < n; i++) {
        ldiph[i] = (s3ssid_t *)calloc(n, sizeof(s3ssid_t));
    }

    rdiph = (s3ssid_t **)calloc(n, sizeof(s3ssid_t *));
    for (int i = 0; i < n; i++) {
        rdiph[i] = (s3ssid_t *)calloc(n, sizeof(s3ssid_t));
    }

    single = (s3ssid_t *)calloc(n, sizeof(s3ssid_t));

    dict2pid->ldiph_lc = (s3ssid_t ***)calloc(n, sizeof(s3ssid_t **));
    for (int i = 0; i < n; i++) {
        dict2pid->ldiph_lc[i] = (s3ssid_t **)calloc(n, sizeof(s3ssid_t *));
        for (int j = 0; j < n; j++) {
            dict2pid->ldiph_lc[i][j] = (s3ssid_t *)calloc(n, sizeof(s3ssid_t));
        }
    }

    dict2pid->single_lc = (s3ssid_t **)calloc(n, sizeof(s3ssid_t *));
    for (int i = 0; i < n; i++) {
        dict2pid->single_lc[i] = (s3ssid_t *)calloc(n, sizeof(s3ssid_t));
    }

    mdef->ciphone = (ciphone_t *)calloc(mdef->n_ciphone, sizeof(ciphone_t));
    for (int i = 0; i < mdef->n_ciphone; i++) {
        mdef->ciphone[i].name = (char *)"";
        mdef->ciphone[i].filler = 0;
    }
}