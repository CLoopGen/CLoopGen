#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

double **matrix;
double **vectors;
double *terms;
double *results;
size_t rank;
size_t number_vectors;
ssize_t i;
ssize_t j;

void init_vars() {
    rank = 1024;
    number_vectors = 512;

    // Allocate terms and results
    terms = (double*)calloc(rank, sizeof(double));
    results = (double*)calloc(number_vectors, sizeof(double));

    // Initialize with non-zero values to ensure meaningful computation
    for (size_t idx = 0; idx < rank; idx++) {
        terms[idx] = 1.0 + (idx % 3) * 0.1;
    }
    for (size_t idx = 0; idx < number_vectors; idx++) {
        results[idx] = 1.5 + (idx % 4) * 0.2;
    }

    // Allocate matrix[rank][rank]
    matrix = (double**)calloc(rank, sizeof(double*));
    for (size_t idx = 0; idx < rank; idx++) {
        matrix[idx] = (double*)calloc(rank, sizeof(double));
    }

    // Allocate vectors[number_vectors][rank]
    vectors = (double**)calloc(number_vectors, sizeof(double*));
    for (size_t idx = 0; idx < number_vectors; idx++) {
        vectors[idx] = (double*)calloc(rank, sizeof(double));
    }
}