#ifndef BINARYHEAP_H_INCLUDED
#define BINARYHEAP_H_INCLUDED
#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"

bool insert_a_key(int* data, int size, int num_element, int key);
int extract(int* data, int num_element);
void build(int* data, int num_element);
void max_heapify(int* data, int pos, int num_element);

bool min_insert_a_key(int* data, int size, int num_element, int key);
int min_extract(int* data, int num_element);
void min_heapify(int* data, int pos, int num_element);

#endif // BINARYHEAP_H_INCLUDED
