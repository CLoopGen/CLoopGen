#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned int md5uint;

typedef md5uint md5sig[4];

typedef struct {
    unsigned int l : 20;
    unsigned int hash_info : 3;
    unsigned int timelimit_impatience : 9;
    unsigned int u : 20;
    unsigned int slvndx : 12;
} flags_t;

struct solution_s {
    md5sig s;
    flags_t flags;
};


typedef struct solution_s solution;

extern unsigned int nsiz;
extern unsigned int h;
extern solution *nsol;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (nsiz > 0) {
        h = 0;
        for (; h < nsiz; ++h)
            nsol[h].flags.hash_info = 0;
    }
}
