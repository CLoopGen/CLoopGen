#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct hentry_st {
    struct hentry_st *next;
    char *filename;
    unsigned short old_id;
    unsigned char need_symlink;
    unsigned char digest[64];
} HENTRY;

typedef struct bucket_st {
    struct bucket_st *next;
    HENTRY *first_entry;
    HENTRY *last_entry;
    unsigned int hash;
    unsigned short type;
    unsigned short num_needed;
} BUCKET;

enum Type {
    TYPE_CERT = 0,
    TYPE_CRL = 1
};

BUCKET *hash_table[257];
enum Type type;
unsigned int hash;
BUCKET *bp;
unsigned int ndx;

static BUCKET buckets_pool[4096];
static HENTRY hentries_pool[8192];
static char filename_pool[16384];

void init_vars() {
    srand((unsigned int)time(NULL));
    
    memset(hash_table, 0, sizeof(hash_table));
    type = TYPE_CERT;
    hash = 0x12345678u;
    bp = NULL;
    ndx = 128;

    size_t bucket_idx = 0;
    size_t hentry_idx = 0;
    size_t fname_idx = 0;

    for (int i = 0; i < 257; i++) {
        if ((rand() % 4) == 0) {
            BUCKET* head = NULL;
            BUCKET* tail = NULL;
            
            int chain_len = rand() % 4;
            if (i == 128) chain_len = 100; 
            
            for (int j = 0; j < chain_len; j++) {
                if (bucket_idx >= 4096) break;
                
                BUCKET* b = &buckets_pool[bucket_idx++];
                b->next = NULL;
                b->first_entry = NULL;
                b->last_entry = NULL;
                b->hash = (i == 128 && j == 50) ? hash : rand() % 0xFFFFFFFEu;
                b->type = (i == 128 && j == 50) ? type : rand() % 2;
                b->num_needed = rand() % 10;

                if (j == 0) {
                    head = b;
                } else {
                    tail->next = b;
                }
                tail = b;

                if (i == 128 && j == 50) {
                    bp = b;
                }

                if ((rand() % 3) == 0) {
                    int entry_count = rand() % 5;
                    HENTRY* e_head = NULL;
                    HENTRY* e_tail = NULL;
                    
                    for (int k = 0; k < entry_count; k++) {
                        if (hentry_idx >= 8192 || fname_idx + 16 >= 16384) break;
                        
                        HENTRY* e = &hentries_pool[hentry_idx++];
                        e->next = NULL;
                        e->old_id = rand() % 65535;
                        e->need_symlink = rand() % 2;
                        for (int d = 0; d < 64; d++) {
                            e->digest[d] = rand() % 256;
                        }
                        
                        int len = 8 + (rand() % 8);
                        e->filename = &filename_pool[fname_idx];
                        for (int c = 0; c < len - 1; c++) {
                            e->filename[c] = 'a' + (rand() % 26);
                        }
                        e->filename[len - 1] = '\0';
                        fname_idx += len;

                        if (!e_head) {
                            e_head = e;
                        } else {
                            e_tail->next = e;
                        }
                        e_tail = e;
                    }
                    b->first_entry = e_head;
                    b->last_entry = e_tail;
                }
            }
            hash_table[i] = head;
        }
    }
}