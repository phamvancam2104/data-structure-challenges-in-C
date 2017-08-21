#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

#define MAX_ELEMENT (100)

int a[MAX_ELEMENT];

int main()
{
    int num_element = 0;
    int i = 0;
    for(i = MAX_ELEMENT; i > 0; i--) {
        min_insert_a_key(a, MAX_ELEMENT, num_element, i);
        num_element++;
    }
    for(i = 0; i < num_element; i ++) {
        printf("%d   ", min_extract(a, num_element - i));
    }
    return 0;
}
