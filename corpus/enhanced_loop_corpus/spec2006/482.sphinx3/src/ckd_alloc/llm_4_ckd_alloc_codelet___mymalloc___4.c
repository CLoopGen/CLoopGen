#include <stdio.h>

#include <inttypes.h>

typedef int int32;

typedef struct mylist_s {
    char **freelist;
    struct mylist_s *next;
    int32 elemsize;
    int32 blocksize;
    int32 blk_alloc;
} mylist_t;

extern int32 elemsize;
extern char *cp;
extern int32 j;
extern char **cpp;
extern mylist_t *list;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (j = list->blocksize - 1; j > 0; --j) {
        if (j % 2 == 1) {
            cp += elemsize;
            *cpp = cp;
            cpp = (char **)cp;
        }
    }
}
