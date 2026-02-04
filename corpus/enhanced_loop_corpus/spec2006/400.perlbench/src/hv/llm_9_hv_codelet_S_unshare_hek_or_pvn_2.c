#include <stdio.h>

#include <inttypes.h>

typedef unsigned int U32;

typedef int I32;

struct hek {
    U32 hek_hash;
    I32 hek_len;
    char hek_key[1];
};


typedef struct hek HEK;

typedef struct he HE;

struct sv {
    void *sv_any;
    U32 sv_refcnt;
    U32 sv_flags;
};


typedef struct sv SV;

struct he {
    HE *hent_next;
    HEK *hent_hek;
    SV *hent_val;
};


extern HEK *hek;
extern HE *entry;
extern HE **oentry;
extern I32 i;
extern I32 found;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Unroll the original loop logic to reduce trip count and increase operations per iteration
    HE *current = *oentry;
    found = 0;
    i = 0;

    // Process up to 4 entries per iteration to reduce loop overhead
    while (current) {
        HE *next1 = current->hent_next;
        if (current->hent_hek == hek) {
            found = 1;
            break;
        }

        if (!next1) break;
        HE *next2 = next1->hent_next;
        if (next1->hent_hek == hek) {
            found = 1;
            current = next1;
            break;
        }

        if (!next2) { current = next2; break; }
        HE *next3 = next2->hent_next;
        if (next2->hent_hek == hek) {
            found = 1;
            current = next2;
            break;
        }

        if (!next3) { current = next3; break; }
        current = next3->hent_next;
        if (next3->hent_hek == hek) {
            found = 1;
            current = next3;
            break;
        }
    }

    // Update external pointers only once at the end to reflect last checked position
    if (found) {
        *oentry = current;
    } else {
        *oentry = current;
        entry = current;
    }
}
