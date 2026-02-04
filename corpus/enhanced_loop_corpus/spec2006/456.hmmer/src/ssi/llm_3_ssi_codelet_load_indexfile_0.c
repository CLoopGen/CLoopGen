#include <stdio.h>

#include <inttypes.h>

typedef unsigned int sqd_uint32;

typedef unsigned short sqd_uint16;

typedef unsigned long long sqd_uint64;

union {
    sqd_uint32 i32;
    sqd_uint64 i64;
};


struct ssioffset_s {
    char mode;
    union {
        sqd_uint32 i32;
        sqd_uint64 i64;
    } off;
};


typedef struct ssioffset_s SSIOFFSET;

struct ssifile_s {
    FILE *fp;
    sqd_uint32 flags;
    sqd_uint16 nfiles;
    sqd_uint32 nprimary;
    sqd_uint32 nsecondary;
    sqd_uint32 flen;
    sqd_uint32 plen;
    sqd_uint32 slen;
    sqd_uint32 frecsize;
    sqd_uint32 precsize;
    sqd_uint32 srecsize;
    SSIOFFSET foffset;
    SSIOFFSET poffset;
    SSIOFFSET soffset;
    char imode;
    char smode;
    char **filename;
    sqd_uint32 *fileformat;
    sqd_uint32 *fileflags;
    sqd_uint32 *bpl;
    sqd_uint32 *rpl;
};


typedef struct ssifile_s SSIFILE;

extern SSIFILE *sfp;
extern sqd_uint16 i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    sqd_uint16 *indices = (sqd_uint16*)__builtin_alloca(sfp->nfiles * sizeof(sqd_uint16));
    for (i = 0; i < sfp->nfiles; i++) {
        indices[i] = sfp->nfiles - 1 - i;
    }
    for (i = 0; i < sfp->nfiles; i++) {
        sfp->filename[indices[i]] = ((void *)0);
    }
}
