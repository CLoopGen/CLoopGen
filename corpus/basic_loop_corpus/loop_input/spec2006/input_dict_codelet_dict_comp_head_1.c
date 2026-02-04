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

typedef int32 s3wid_t;

typedef struct {
    char *word;
    s3cipid_t *ciphone;
    int32 pronlen;
    s3wid_t alt;
    s3wid_t basewid;
    int32 n_comp;
    s3wid_t *comp;
} dictword_t;

typedef struct {
    mdef_t *mdef;
    hash_table_t *pht;
    char **ciphone_str;
    int32 n_ciphone;
    dictword_t *word;
    hash_table_t *ht;
    int32 max_words;
    int32 n_word;
    int32 filler_start;
    int32 filler_end;
    s3wid_t *comp_head;
    s3wid_t startwid;
    s3wid_t finishwid;
    s3wid_t silwid;
} dict_t;

dict_t *d;
int32 w;
s3wid_t *comp_head;

static mdef_t g_mdef;
static dictword_t *g_words;
static s3wid_t *g_comp_head;
static hash_table_t g_ht;
static hash_table_t g_pht;
static hash_table_t g_ciphone_ht;

void init_vars() {
    const int32 target_size = 1 << 20; // Aim for ~1MB of data to get ~0.01s runtime
    d = (dict_t*)calloc(1, sizeof(dict_t));
    g_words = (dictword_t*)calloc(target_size, sizeof(dictword_t));
    g_comp_head = (s3wid_t*)calloc(target_size, sizeof(s3wid_t));
    comp_head = g_comp_head;
    d->word = g_words;
    d->n_word = target_size;
    d->max_words = target_size;
    d->comp_head = g_comp_head;
    d->mdef = &g_mdef;
    d->pht = &g_pht;
    d->ht = &g_ht;
    d->n_ciphone = 100;
    d->filler_start = 0;
    d->filler_end = 10;
    d->startwid = 0;
    d->finishwid = 1;
    d->silwid = 2;

    // Initialize hash tables
    g_ht.table = NULL;
    g_ht.size = 0;
    g_ht.nocase = 0;
    g_pht.table = NULL;
    g_pht.size = 0;
    g_pht.nocase = 0;
    g_ciphone_ht.table = NULL;
    g_ciphone_ht.size = 0;
    g_ciphone_ht.nocase = 0;

    // Allocate and initialize words
    for (int32 i = 0; i < target_size; i++) {
        g_words[i].word = NULL;
        g_words[i].ciphone = NULL;
        g_words[i].pronlen = 0;
        g_words[i].alt = -1;
        g_words[i].basewid = -1;
        g_words[i].n_comp = (i % 7 == 0) ? 1 : 0;  // Every 7th word has a component
        if (g_words[i].n_comp > 0) {
            g_words[i].comp = (s3wid_t*)malloc(sizeof(s3wid_t));
            g_words[i].comp[0] = (i + 1) % target_size;  // Valid index within range
        } else {
            g_words[i].comp = NULL;
        }
    }

    // Initialize mdef
    g_mdef.n_ciphone = 100;
    g_mdef.n_phone = 1000;
    g_mdef.n_emit_state = 5000;
    g_mdef.n_ci_sen = 200;
    g_mdef.n_sen = 1000;
    g_mdef.n_tmat = 50;
    g_mdef.ciphone_ht = &g_ciphone_ht;
    g_mdef.ciphone = NULL;
    g_mdef.phone = NULL;
    g_mdef.sseq = NULL;
    g_mdef.n_sseq = 0;
    g_mdef.cd2cisen = NULL;
    g_mdef.sen2cimap = NULL;
    g_mdef.ciphone2n_cd_sen = NULL;
    g_mdef.sil = 0;
    g_mdef.wpos_ci_lclist = NULL;
}