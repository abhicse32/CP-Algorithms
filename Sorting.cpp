#include <bits/stdc++.h>
#define vi vector<int>
using namespace std;

void bubble_sort(vi& arr){
    int n = arr.size();
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n-1; ++j)
            if(arr[j] > arr[j+1]) 
                swap(arr[j], arr[j+1]);
    }
}

void insertion_sort(vi& arr){
    int n = arr.size(), i, j;
    for(i = 1; i < n; ++i){
        int tmp = arr[i];
        for(j = i-1; j>=0 && arr[j] > tmp; --j)
            arr[j+1] = arr[j];
        arr[j+1] = tmp;
    }
}

void selection_sort(vi& arr){

}

void print_arr(vi& arr){
    for(auto v: arr) cout << v <<" ";
    cout <<endl;
}
int main(){
    vi arr{7, 5, 3, 1, 9, 8};
    insertion_sort(arr);
    print_arr(arr);
}
