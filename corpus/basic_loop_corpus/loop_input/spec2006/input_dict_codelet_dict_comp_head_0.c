#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

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

void init_vars() {
    d = (dict_t *)calloc(1, sizeof(dict_t));
    d->max_words = 5000000;
    d->n_word = 5000000;
    d->comp_head = (s3wid_t *)calloc(d->max_words, sizeof(s3wid_t));
    comp_head = d->comp_head;

    d->mdef = (mdef_t *)calloc(1, sizeof(mdef_t));
    d->mdef->n_ciphone = 1000;
    d->mdef->ciphone = (ciphone_t *)calloc(d->mdef->n_ciphone, sizeof(ciphone_t));
    for (int i = 0; i < d->mdef->n_ciphone; i++) {
        d->mdef->ciphone[i].name = (char *)"ci";
        d->mdef->ciphone[i].filler = 0;
    }

    d->mdef->ciphone_ht = (hash_table_t *)calloc(1, sizeof(hash_table_t));
    d->mdef->ciphone_ht->size = 128;
    d->mdef->ciphone_ht->nocase = 1;
    d->mdef->ciphone_ht->table = (hash_entry_t *)calloc(128, sizeof(hash_entry_t));

    d->mdef->phone = (phone_t *)calloc(10000, sizeof(phone_t));
    d->mdef->n_phone = 10000;

    d->mdef->sen2cimap = (s3cipid_t *)calloc(20000, sizeof(s3cipid_t));
    d->mdef->n_sen = 20000;
    d->mdef->n_ci_sen = 5000;

    d->mdef->cd2cisen = (s3senid_t *)calloc(30000, sizeof(s3senid_t));
    d->mdef->n_emit_state = 30000;

    d->mdef->ciphone2n_cd_sen = (int32 *)calloc(d->mdef->n_ciphone, sizeof(int32));
    for (int i = 0; i < d->mdef->n_ciphone; i++) {
        d->mdef->ciphone2n_cd_sen[i] = 30;
    }

    d->mdef->sil = 0;

    d->mdef->wpos_ci_lclist = (ph_lc_t ***)calloc(5, sizeof(ph_lc_t **));
    for (int i = 0; i < 5; i++) {
        d->mdef->wpos_ci_lclist[i] = (ph_lc_t **)calloc(d->mdef->n_ciphone, sizeof(ph_lc_t *));
    }

    d->pht = (hash_table_t *)calloc(1, sizeof(hash_table_t));
    d->pht->size = 256;
    d->pht->nocase = 1;
    d->pht->table = (hash_entry_t *)calloc(256, sizeof(hash_entry_t));

    d->ciphone_str = (char **)calloc(d->mdef->n_ciphone, sizeof(char *));
    for (int i = 0; i < d->mdef->n_ciphone; i++) {
        d->ciphone_str[i] = (char *)"ci";
    }
    d->n_ciphone = d->mdef->n_ciphone;

    d->word = (dictword_t *)calloc(d->n_word, sizeof(dictword_t));
    for (int i = 0; i < d->n_word; i++) {
        d->word[i].word = (char *)"word";
        d->word[i].pronlen = 1;
        d->word[i].ciphone = (s3cipid_t *)calloc(1, sizeof(s3cipid_t));
        d->word[i].ciphone[0] = 0;
        d->word[i].alt = -1;
        d->word[i].basewid = i;
        d->word[i].n_comp = 0;
        d->word[i].comp = NULL;
    }

    d->ht = (hash_table_t *)calloc(1, sizeof(hash_table_t));
    d->ht->size = 1024;
    d->ht->nocase = 1;
    d->ht->table = (hash_entry_t *)calloc(1024, sizeof(hash_entry_t));

    d->filler_start = 100;
    d->filler_end = 200;
    d->startwid = 0;
    d->finishwid = 1;
    d->silwid = 2;
}