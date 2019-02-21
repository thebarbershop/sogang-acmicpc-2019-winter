#include <cstdio>
#include <vector>
using std::vector;


void merge(vector<int>&, int, int);
void merge_sort(vector<int> &, int, int);
void print(vector<int> &);


int main(void) {
    vector<int> array = {38, 27, 43, 3, 9, 82, 10};
    print(array);
    merge_sort(array, 0, array.size());
    return 0;
}

void merge(vector<int> &array, int left, int right) {
    int mid = (left+right)/2;
    vector<int> result;
    int left_index = left, right_index = mid;
    while(left_index < mid && right_index < right) {
        if(array[left_index] < array[right_index]) {
            result.push_back(array[left_index]);
            left_index++;
        }
        else {
            result.push_back(array[right_index]);
            right_index++;
        }
    }
    while(left_index < mid) {
        result.push_back(array[left_index]);
        left_index++;
    }
    while(right_index < right) {
        result.push_back(array[right_index]);
        right_index++;
    }
    for(int i = 0; i < result.size(); i++) {
        array[left+i] = result[i];
    }
}

void merge_sort(vector<int> &array, int left, int right) {
    /* sort ARRAY from LEFT to RIGHT-1 */
    if(left == right-1) {
        return;
    }
    int mid = (left+right)/2;
    merge_sort(array, left, mid);
    merge_sort(array, mid, right);
    printf("Merging from %d to %d\n", left, right);
    merge(array, left, right);
    print(array);
}

void print(vector<int> &array) {
    for(auto &elem: array) {
        printf("%d ", elem);
    }
    printf("\n");
}