#include <stdio.h>
#include <stdlib.h>
#define swap(a,b,t) {t=a; a = b; b = t;}
void sift_up(int* a, int i);
void sift_down(int* a, int i, int num_element);

int log(int n) {
    int ret = 0;
    n = n + 1;
    int initial = n;
    while((initial/2) > 0) {
    	initial = initial / 2;
        ret++;
    }
    return ret;
}

void insert(int* a, int num_element, int key) {
    int childIndex = num_element;
    a[childIndex] = key;
    int level = log(childIndex);
    sift_up(a, childIndex);
}


int deleteMin(int* a, int num_element) {
    int ret = a[0];
    int temp = 0;
    swap(a[0], a[num_element - 1], temp);
    sift_down(a, 0, num_element-1);
    return ret;
}

int deleteMax(int* a, int num_element) {
    int temp = 0;
    int max = 0;
    max = ((num_element > 1) && (a[max] < a[1]))? 1:max;
    max = ((num_element > 2) && (a[max] < a[2]))? 2:max;
    int ret = a[max];
    swap(a[max], a[num_element - 1], temp);
    sift_down(a, max, num_element - 1) ;
    return ret;
}

void sift_up(int* a, int i) {
    if (i <= 0) return;
    int temp;
    int parent = (i - 1) >> 1;
    int level = log(i);
    if (level % 2 == 0) {
        //even level: it is smaller than its parent
        if (a[i] > a[parent]) {
            swap(a[i], a[parent], temp);
            sift_up(a, parent);
        } else {
            int parentOfParent = (parent - 1) >> 1;
            if (parentOfParent >= 0 && a[i] < a[parentOfParent]) {
            	swap(a[i], a[parentOfParent], temp);
            	sift_up(a, parentOfParent);	
			}
        }
    } else {
        //odd level: it is greater than its parent
        if (a[i] > a[parent]) {
            int parentOfParent = (parent - 1) >= 0 ? (parent-1)/2:-1;
            if (parentOfParent >= 0 && a[i] > a[parentOfParent]) {
            	swap(a[i], a[parentOfParent], temp);
            	sift_up(a, parentOfParent);
			}
        } else {
            swap(a[i], a[parent], temp);
            sift_up(a, parent);
        }
    }
}


void sift_down(int* a, int i, int num_element) {
    if (num_element <= 1) return;
    int left = i * 2 + 1;
    int right = i * 2 + 2;
    int temp;
    int level = log(i);
    if (level % 2 == 0) {
        //even level: it is smaller than its descendants
        int min = i;
        min = left < num_element && a[min] > a[left] ? left:min;
        min = right < num_element && a[min] > a[right] ? right:min;
        min = 2 * left + 1 < num_element && a[min] > a[2 * left + 1] ? 2 * left + 1:min;
        min = 2 * left + 2 < num_element && a[min] > a[2 * left + 2] ? 2 * left + 2:min;
        min = 2 * right + 1 < num_element && a[min] > a[2 * right + 1] ? 2 * right + 1:min;
        min = 2 * right + 2 < num_element && a[min] > a[2 * right + 2] ? 2 * right + 2:min;
        if (min == left || min == right) {
            swap(a[i], a[min], temp);
            sift_down(a, min, num_element);
        } else if (min != i) {
            swap(a[i], a[min], temp);
            if (a[min] > a[(min - 1)/2]) {
            	swap(a[min], a[(min - 1)/2], temp);
			}
            sift_down(a, min, num_element);
        }
    } else {
        //odd level: it is greater than its descendants
        int max = i;
        max = left < num_element && a[max] < a[left] ? left:max;
        max = right < num_element && a[max] < a[right] ? right:max;
        max = (2 * left + 1 < num_element) && (a[max] < a[2 * left + 1]) ?2 * left + 1:max;
        max = (2 * left + 2 < num_element) && (a[max] < a[2 * left + 2] )? 2 * left + 2:max;
        max = ((2 * right + 1 < num_element) && (a[max] < a[2 * right + 1]))? 2 * right + 1:max;
        max = ((2 * right + 2 < num_element) && (a[max] < a[2 * right + 2]))? 2 * right + 2:max;
        if (max == left || max == right) {
            swap(a[i], a[max], temp);
            sift_down(a, max, num_element);
        } else if (max != i) {
            swap(a[i], a[max], temp);
            if (a[max] < a[(max - 1)/2]) {
            	swap(a[max], a[(max - 1)/2], temp);
			}
            sift_down(a, max, num_element);
        }
    }
}


#define MAX_ELEMENT (100)
int main()
{
    int i = 0;
    int a[MAX_ELEMENT];
    int num = 0;
    for (i =0; i < MAX_ELEMENT; i++) {
        insert(a, num++, i);
    }
    for (i = 0; i < (MAX_ELEMENT + 1)/2; i++){
    	if (num > 0) {
    		printf("%d   ", deleteMax(a, num--));
		} 
		if (num > 0) {
			printf("%d   ", deleteMin(a, num--));
		}  
    }
    getchar();
    return 0;
}

