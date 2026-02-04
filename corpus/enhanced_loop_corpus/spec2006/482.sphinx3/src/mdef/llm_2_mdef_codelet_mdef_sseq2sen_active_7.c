#include <stdio.h>

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

extern mdef_t *mdef;
extern int32 *sseq;
extern int32 *sen;
extern int32 ss;
extern int32 i;
extern s3senid_t *sp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided Memory Access Pattern
    // Instead of accessing sseq[ss] and mdef->sseq[ss] consecutively, we modify the inner loop to use a stride of 2,
    // processing elements in a non-consecutive but predictable pattern. We also ensure coverage by handling remainder.

    int32 n_sseq = mdef->n_sseq;
    int32 n_emit_state = mdef->n_emit_state;

    for (ss = 0; ss < n_sseq; ss += 2) {
        if (sseq[ss]) {
            sp = mdef->sseq[ss];
            for (i = 0; i < n_emit_state; i++) {
                sen[sp[i]] = 1;
            }
        }
        // Handle next element in pair if within bounds
        if ((ss + 1) < n_sseq && sseq[ss + 1]) {
            sp = mdef->sseq[ss + 1];
            for (i = 0; i < n_emit_state; i++) {
                sen[sp[i]] = 1;
            }
        }
    }
}
