#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef enum {
    UndefinedKernel,
    UnityKernel,
    GaussianKernel,
    DoGKernel,
    LoGKernel,
    BlurKernel,
    CometKernel,
    BinomialKernel,
    LaplacianKernel,
    SobelKernel,
    FreiChenKernel,
    RobertsKernel,
    PrewittKernel,
    CompassKernel,
    KirschKernel,
    DiamondKernel,
    SquareKernel,
    RectangleKernel,
    OctagonKernel,
    DiskKernel,
    PlusKernel,
    CrossKernel,
    RingKernel,
    PeaksKernel,
    EdgesKernel,
    CornersKernel,
    DiagonalsKernel,
    LineEndsKernel,
    LineJunctionsKernel,
    RidgesKernel,
    ConvexHullKernel,
    ThinSEKernel,
    SkeletonKernel,
    ChebyshevKernel,
    ManhattanKernel,
    OctagonalKernel,
    EuclideanKernel,
    UserDefinedKernel
} KernelInfoType;

typedef double MagickDoubleType;
typedef MagickDoubleType MagickRealType;

typedef struct _KernelInfo {
    KernelInfoType type;
    size_t width;
    size_t height;
    ssize_t x;
    ssize_t y;
    MagickRealType *values;
    double minimum;
    double maximum;
    double negative_range;
    double positive_range;
    double angle;
    struct _KernelInfo *next;
    size_t signature;
} KernelInfo;

KernelInfo *color_matrix;
double ColorMatrix[6][6];
ssize_t i;
ssize_t u;
ssize_t v;

void init_vars() {
    const size_t data_size = 128 * 1024 * 1024; // ~128MB of data
    const size_t matrix_elements = 6 * 6;
    
    // Allocate values array to be large enough
    MagickRealType *values = (MagickRealType*)calloc(data_size / sizeof(MagickRealType), sizeof(MagickRealType));
    if (!values) exit(1);

    // Initialize color_matrix structure
    color_matrix = (KernelInfo*)malloc(sizeof(KernelInfo));
    if (!color_matrix) exit(1);

    // Set dimensions such that the loop runs long enough (~0.01 sec)
    // We'll make width and height large but ensure inner condition (v<6 && u<6) only copies first 6x6
    color_matrix->width = 10000;
    color_matrix->height = (data_size / sizeof(MagickRealType)) / color_matrix->width;
    if (color_matrix->height == 0) color_matrix->height = 1;

    // Ensure total size fits within allocated values
    size_t required_size = color_matrix->width * color_matrix->height;
    if (required_size > data_size / sizeof(MagickRealType)) {
        required_size = data_size / sizeof(MagickRealType);
        // Adjust dimensions to fit
        color_matrix->height = required_size / color_matrix->width;
    }

    color_matrix->values = values;
    color_matrix->type = UserDefinedKernel;
    color_matrix->x = 0;
    color_matrix->y = 0;
    color_matrix->minimum = 0.0;
    color_matrix->maximum = 1.0;
    color_matrix->negative_range = -0.5;
    color_matrix->positive_range = 0.5;
    color_matrix->angle = 0.0;
    color_matrix->next = NULL;
    color_matrix->signature = 0x12345678;

    // Initialize ColorMatrix to zero
    for (ssize_t iv = 0; iv < 6; iv++)
        for (ssize_t iu = 0; iu < 6; iu++)
            ColorMatrix[iv][iu] = 0.0;

    // Initialize index i used in loop
    i = 0;

    // Initialize all values in the kernel to non-zero to avoid optimization issues
    for (size_t idx = 0; idx < required_size; idx++) {
        values[idx] = (MagickRealType)(idx % 100) / 100.0;
    }
}