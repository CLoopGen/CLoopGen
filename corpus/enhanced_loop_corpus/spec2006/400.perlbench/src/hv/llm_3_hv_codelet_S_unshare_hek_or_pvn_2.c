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
    // Variant 2: Indirect Access via Array-like Indexing Using Pointer Arithmetic
    // Simulate indirect access by first collecting entries into a local array (up to a limit),
    // then iterating over them using indexed access with non-linear traversal (e.g., reverse order).
    HE *temp_buffer[256];  // Local buffer to store pointers temporarily
    I32 count = 0;
    HE *current = *oentry;

    // Collect up to 256 entries or until end of list
    while (current && count < 255) {
        temp_buffer[count++] = current;
        current = *( &(current)->hent_next );
    }
    temp_buffer[count] = NULL;

    // Now traverse the collected pointers in reverse (indirect, non-sequential access pattern)
    found = 0;
    i = 0;
    for (I32 idx = count - 1; idx >= 0; idx--) {
        entry = temp_buffer[idx];
        if ((entry)->hent_hek == hek) {
            found = 1;
            break;
        }
        // Update oentry as per original semantics (simulate pointer-to-pointer update)
        oentry = &(entry)->hent_next;
    }
    // Finalize state as in original: ensure i is set and oentry updated
    i = 0;
}
