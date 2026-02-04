#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

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

typedef double float64;

typedef struct {
    dict_t *dict;
    int32 *prob;
    float64 lw;
    float64 wip;
} fillpen_t;

dict_t *dict;
s3wid_t w;
s3wid_t bw;
fillpen_t *_fillpen;

void init_vars() {
    const int32 num_fillers = 5000000;  // ~20MB of data, target ~0.01 sec runtime

    // Allocate and initialize _fillpen->prob
    int32 *fill_prob = (int32*)calloc(num_fillers, sizeof(int32));
    for (int i = 0; i < num_fillers; i++) {
        fill_prob[i] = rand() % 1000;
    }

    _fillpen = (fillpen_t*)malloc(sizeof(fillpen_t));
    _fillpen->dict = NULL;
    _fillpen->prob = fill_prob;
    _fillpen->lw = 1.0;
    _fillpen->wip = 0.1;

    // Initialize dict
    dict = (dict_t*)malloc(sizeof(dict_t));
    memset(dict, 0, sizeof(dict_t));

    dict->filler_start = 0;
    dict->filler_end = num_fillers - 1;
    dict->max_words = num_fillers;
    dict->n_word = num_fillers;

    // Allocate and initialize dict->word array
    dictword_t *words = (dictword_t*)calloc(num_fillers, sizeof(dictword_t));
    for (int i = 0; i < num_fillers; i++) {
        words[i].basewid = (i % 10 == 0) ? i : (rand() % i);  // Some point to earlier entries
        words[i].pronlen = 1;
        words[i].ciphone = (s3cipid_t*)malloc(sizeof(s3cipid_t));
        words[i].ciphone[0] = i % 256;
        words[i].word = (char*)malloc(16);
        sprintf(words[i].word, "fill_%d", i);
        words[i].alt = -1;
        words[i].n_comp = 0;
        words[i].comp = NULL;
    }
    dict->word = words;
    dict->comp_head = NULL;
    dict->startwid = 0;
    dict->finishwid = 1;
    dict->silwid = 2;
}