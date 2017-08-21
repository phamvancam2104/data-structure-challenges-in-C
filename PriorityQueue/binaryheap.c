#include "binaryheap.h"
#include "utils.h"

bool insert_a_key(int* data, int size, int num_element, int key) {
    if (size <= 0 || num_element >= size || data == NULL) {
        return false;
    }
    int childIndex = num_element;
    //insert the key
    data[num_element] = key;
    if (childIndex == 0) {
        return true;
    }
    //up-heap
    int temp = 0;
    bool finished = false;
    while (!finished) {
        int parentIndex = (childIndex - 1)/2;
        if (data[childIndex] > data[parentIndex]) {
            //swap parent and children
            swap(data[childIndex], data[parentIndex], temp);
            childIndex = parentIndex;
            parentIndex = (childIndex - 1)/2;
        } else {
            finished = true;
        }
    }
    return true;
}


int extract(int* data, int num_element) {
    int ret = data[0];
    int temp = 0;

    swap(data[0], data[num_element - 1], temp);
    num_element--;
    max_heapify(data, 0, num_element);

    return ret;
}

void build(int* data, int num_element) {
    int i = 0;
    int max_index = (num_element - 1)/2;
    for (i = max_index; i >= 0 ; i--) {
        max_heapify(data, i, num_element);
    }
}

void max_heapify(int* data, int pos, int num_element) {
    int left = 2 * pos + 1;
    int right = 2 * pos + 2;
    int largest = left < num_element && data[pos] < data[left] ? left:pos;
    largest =  right < num_element && data[largest] < data[right] ? right:largest;
    if (largest != pos) {
        int temp = 0;
        swap(data[largest], data[pos], temp);
        max_heapify(data, largest, num_element);
    }
}


bool min_insert_a_key(int* data, int size, int num_element, int key) {
    if (size <= 0 || num_element >= size || data == NULL) {
        return false;
    }
    int childIndex = num_element;
    //insert the key
    data[num_element] = key;
    if (childIndex == 0) {
        return true;
    }
    //up-heap
    int temp = 0;
    bool finished = false;
    while (!finished) {
        int parentIndex = (childIndex - 1)/2;
        if (data[childIndex] < data[parentIndex]) {
            //swap parent and children
            swap(data[childIndex], data[parentIndex], temp);
            childIndex = parentIndex;
            parentIndex = (childIndex - 1)/2;
        } else {
            finished = true;
        }
    }
    return true;
}


int min_extract(int* data, int num_element) {
    int ret = data[0];
    int temp = 0;

    swap(data[0], data[num_element - 1], temp);
    num_element--;
    min_heapify(data, 0, num_element);

    return ret;
}


void min_heapify(int* data, int pos, int num_element) {
    int left = 2 * pos + 1;
    int right = 2 * pos + 2;
    int largest = left < num_element && data[pos] > data[left] ? left:pos;
    largest =  right < num_element && data[largest] > data[right] ? right:largest;
    if (largest != pos) {
        int temp = 0;
        swap(data[largest], data[pos], temp);
        min_heapify(data, largest, num_element);
    }
}



