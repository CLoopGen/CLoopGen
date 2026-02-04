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



void loop() {
    // Variant 1: Strided Memory Access Pattern
    // Instead of traversing the linked list normally, simulate a strided access by skipping every other node.
    // This changes the memory access pattern to non-consecutive, potentially affecting cache behavior.
    I32 stride = 0;
    for (entry = *oentry; entry; i = 0, oentry = &(entry)->hent_next, entry = *oentry) {
        if (stride % 2 == 0) {  // Only process every second node
            if ((entry)->hent_hek == hek) {
                found = 1;
                break;
            }
        }
        stride++;
        // Advance an extra step if possible to create stride
        if (entry && entry->hent_next) {
            entry = entry->hent_next;
            oentry = &(entry)->hent_next;
        } else {
            break;
        }
    }
}
