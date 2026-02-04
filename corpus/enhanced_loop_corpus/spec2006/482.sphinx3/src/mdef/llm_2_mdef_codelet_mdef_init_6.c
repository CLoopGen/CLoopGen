#include <stdio.h>

#include <inttypes.h>

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

extern int32 n;
extern s3pid_t p;
extern mdef_t *m;
extern int32 *cdsen_start;
extern int32 *cdsen_end;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided Memory Access Pattern
    // Instead of iterating sequentially over ciphone2n_cd_sen and cdsen_start/end with stride 1,
    // we access elements with a fixed stride (e.g., 2), processing every other element in two passes.
    // This simulates scenarios where data access is non-consecutive due to padding or filtering.

    int32 stride = 2;
    int32 i;

    // First pass: even indices
    for (i = 0; i < m->n_ciphone; i += stride) {
        if (cdsen_start[i] > 0) {
            m->ciphone2n_cd_sen[i] = cdsen_end[i] - cdsen_start[i] + 1;
            n += m->ciphone2n_cd_sen[i];
        }
    }

    // Second pass: odd indices
    for (i = 1; i < m->n_ciphone; i += stride) {
        if (cdsen_start[i] > 0) {
            m->ciphone2n_cd_sen[i] = cdsen_end[i] - cdsen_start[i] + 1;
            n += m->ciphone2n_cd_sen[i];
        }
    }
}
