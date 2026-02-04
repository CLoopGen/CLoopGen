#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int int32;

typedef struct mylist_s {
    char **freelist;
    struct mylist_s *next;
    int32 elemsize;
    int32 blocksize;
    int32 blk_alloc;
} mylist_t;

int32 elemsize;
char *cp;
int32 j;
char **cpp;
mylist_t *list;

static char *data_buffer;
static char **ptr_buffer;

void init_vars() {
    // Set element size to 16 bytes for realistic alignment and access pattern
    elemsize = 16;

    // Aim for approximately 64K iterations to achieve ~0.01s runtime on modern CPUs
    int32 target_blocksize = 65536;

    // Total data buffer size: (blocksize) * elemsize, plus some headroom
    size_t data_size = target_blocksize * elemsize;
    
    // Allocate aligned memory to ensure proper addressing
    data_buffer = (char *)aligned_alloc(64, data_size);
    if (!data_buffer) exit(1);
    
    // Clear the buffer
    memset(data_buffer, 0, data_size);

    // Allocate memory for pointer tracking if needed
    ptr_buffer = (char **)aligned_alloc(64, sizeof(char **) * target_blocksize);
    if (!ptr_buffer) exit(1);
    memset(ptr_buffer, 0, sizeof(char **) * target_blocksize);

    // Initialize list structure
    list = (mylist_t *)malloc(sizeof(mylist_t));
    if (!list) exit(1);

    list->elemsize = elemsize;
    list->blocksize = target_blocksize;
    list->blk_alloc = 1;
    list->next = NULL;
    list->freelist = ptr_buffer;

    // Initialize cp to start of data buffer + elemsize (since loop does j = blocksize-1 down to 1)
    cp = data_buffer + elemsize;

    // Initialize cpp to point to the first freelist slot
    cpp = &(list->freelist[0]);
}