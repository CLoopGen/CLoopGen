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
    int32 step = 2;
    for (j = list->blocksize - 1; j > 0; j -= step) {
        cp += elemsize;
        *cpp = cp;
        cpp = (char **)cp;
        // Add extra arithmetic to increase computational intensity
        cp += elemsize;
        if (j > 1) {
            *cpp = cp;
            cpp = (char **)cp;
        }
    }
}
