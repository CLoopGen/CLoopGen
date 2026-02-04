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

extern int32 s;
extern mdef_t *m;
extern int32 *cdsen_start;
extern int32 *cdsen_end;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int32 block_size = 4;
    int32 limit = m->n_sen - (m->n_sen % block_size);
    for (s = m->n_ci_sen; s < limit; s += block_size) {
        int32 mapped0 = (int)m->sen2cimap[s + 0];
        int32 mapped1 = (int)m->sen2cimap[s + 1];
        int32 mapped2 = (int)m->sen2cimap[s + 2];
        int32 mapped3 = (int)m->sen2cimap[s + 3];

        if (mapped0 >= 0) {
            if (!cdsen_start[mapped0]) cdsen_start[mapped0] = s + 0;
            cdsen_end[mapped0] = s + 0;
        }
        if (mapped1 >= 0) {
            if (!cdsen_start[mapped1]) cdsen_start[mapped1] = s + 1;
            cdsen_end[mapped1] = s + 1;
        }
        if (mapped2 >= 0) {
            if (!cdsen_start[mapped2]) cdsen_start[mapped2] = s + 2;
            cdsen_end[mapped2] = s + 2;
        }
        if (mapped3 >= 0) {
            if (!cdsen_start[mapped3]) cdsen_start[mapped3] = s + 3;
            cdsen_end[mapped3] = s + 3;
        }
    }
    for (; s < m->n_sen; s++) {
        if (((m->sen2cimap[s]) < 0))
            continue;
        if (!cdsen_start[(int)m->sen2cimap[s]])
            cdsen_start[(int)m->sen2cimap[s]] = s;
        cdsen_end[(int)m->sen2cimap[s]] = s;
    }
}
