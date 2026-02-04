#include <stdint.h>
#include <stdlib.h>
#include <string.h>

int ***mask;
int mask_linesize;
int image_linesize;
int mask_size;
int start_posx;
int start_posy;
int end_posx;
int end_posy;
int i;
int j;
unsigned int accumulator;
unsigned int divisor;
uint8_t *image_read_position;
uint8_t *mask_read_position;

static uint8_t *image_buffer;
static uint8_t *mask_linear_buffer;
static int **mask_second_level;
static int ***mask_third_level;

void init_vars() {
    // Define dimensions
    const int width = 2048;   // ~2KB per line, total image ~4MB
    const int height = 1024;
    
    mask_size = 5;
    start_posx = 2;
    start_posy = 2;
    end_posx = width - 3;
    end_posy = height - 3;
    
    image_linesize = width;
    mask_linesize = (end_posx - start_posx + 1);
    
    // Allocate image buffer
    image_buffer = (uint8_t*)calloc(width * height, sizeof(uint8_t));
    if (!image_buffer) exit(1);
    
    // Initialize with non-zero pattern for realistic access
    for (int idx = 0; idx < width * height; idx++) {
        image_buffer[idx] = (uint8_t)(idx % 251);
    }
    
    // Allocate mask read position linear buffer
    mask_linear_buffer = (uint8_t*)calloc(mask_linesize * (end_posy - start_posy + 1), sizeof(uint8_t));
    if (!mask_linear_buffer) exit(1);
    
    // Randomly initialize mask_read_position data (simulate valid/invalid pixels)
    for (int idx = 0; idx < mask_linesize * (end_posy - start_posy + 1); idx++) {
        mask_linear_buffer[idx] = rand() % 2 ? 0 : 1;
    }
    
    // Setup 3D mask array: [mask_size+1][local_width][local_height]
    int local_width = end_posx - start_posx + 1;
    int local_height = end_posy - start_posy + 1;
    
    mask_third_level = (int***)calloc(mask_size + 1, sizeof(int**));
    if (!mask_third_level) exit(1);
    
    mask_second_level = (int**)calloc((mask_size + 1) * local_width, sizeof(int*));
    if (!mask_second_level) exit(1);
    
    int* mask_data = (int*)calloc((mask_size + 1) * local_width * local_height, sizeof(int));
    if (!mask_data) exit(1);
    
    for (int m = 0; m <= mask_size; m++) {
        mask_third_level[m] = &mask_second_level[m * local_width];
        for (int x = 0; x < local_width; x++) {
            mask_third_level[m][x] = &mask_data[m * local_width * local_height + x * local_height];
            for (int y = 0; y < local_height; y++) {
                mask_third_level[m][x][y] = (m == mask_size) ? (rand() % 2) : 0;
            }
        }
    }
    
    // Initialize global pointers
    mask = mask_third_level;
    image_read_position = image_buffer + (start_posy * width + start_posx);
    mask_read_position = mask_linear_buffer;
    
    accumulator = 0;
    divisor = 0;
}