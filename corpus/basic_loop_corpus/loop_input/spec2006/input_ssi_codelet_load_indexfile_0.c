#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

SSIFILE *sfp;
sqd_uint16 i;

void init_vars() {
    const size_t data_size = 1 << 20; // ~1MB to ensure ~0.01 sec runtime
    sfp = (SSIFILE*)calloc(1, sizeof(SSIFILE));
    if (!sfp) exit(1);

    sfp->nfiles = (sqd_uint16)(data_size / sizeof(char*)); // Scale nfiles to allocate ~1MB for filename array of pointers
    if (sfp->nfiles == 0) sfp->nfiles = 1;

    sfp->filename = (char**)calloc(sfp->nfiles, sizeof(char*));
    if (!sfp->filename) exit(1);

    sfp->fileformat = (sqd_uint32*)calloc(sfp->nfiles, sizeof(sqd_uint32));
    sfp->fileflags = (sqd_uint32*)calloc(sfp->nfiles, sizeof(sqd_uint32));
    sfp->bpl = (sqd_uint32*)calloc(sfp->nfiles, sizeof(sqd_uint32));
    sfp->rpl = (sqd_uint32*)calloc(sfp->nfiles, sizeof(sqd_uint32));

    if (!sfp->fileformat || !sfp->fileflags || !sfp->bpl || !sfp->rpl) exit(1);
}