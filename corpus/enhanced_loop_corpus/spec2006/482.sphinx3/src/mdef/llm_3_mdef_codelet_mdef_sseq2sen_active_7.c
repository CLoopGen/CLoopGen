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
    // Variant 2: Indirect Memory Access via Index Array
    // Use an auxiliary index array to access sseq and mdef->sseq indirectly.
    // This simulates a gather-style access pattern where the order of iteration is determined by an index map.
    // For realism, we assume the index array is precomputed (here simulated on-stack for fixed size).

    int32 n_sseq = mdef->n_sseq;
    int32 n_emit_state = mdef->n_emit_state;
    int32 idx_map[256];  // Simulated precomputed permutation index (limited size for example)

    // Simulate a simple reverse mapping as indirect access pattern
    for (int j = 0; j < n_sseq && j < 256; j++) {
        idx_map[j] = n_sseq - 1 - j;
    }

    for (ss = 0; ss < n_sseq && ss < 256; ss++) {
        int32 idx = idx_map[ss];  // Indirect access index
        if (sseq[idx]) {
            sp = mdef->sseq[idx];
            for (i = 0; i < n_emit_state; i++) {
                sen[sp[i]] = 1;
            }
        }
    }
}
