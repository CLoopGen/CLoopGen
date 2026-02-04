#include <stdio.h>

#include <inttypes.h>

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


extern BUCKET *hash_table[257];
extern enum Type type;
extern unsigned int hash;
extern BUCKET *bp;
extern unsigned int ndx;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    BUCKET *current;
    for (unsigned int i = 0; i <= ndx; ++i) {
        for (current = hash_table[i]; current; current = current->next) {
            if (i == ndx && current->type == type && current->hash == hash) {
                bp = current;
                return;
            }
        }
    }
    bp = NULL;
}
