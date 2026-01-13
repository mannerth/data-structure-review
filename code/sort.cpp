#include<iostream>
#include<list>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;

/// @brief 桶排序
/// @param 数组
/// @param 数组大小
void binSort(int* arr, int size, int range){
    //初始化
    list<int> *bin = new list<int> [range+1];

    //把元素放到对应的桶里
    for(int i = 0; i < size; ++i){
        bin[ arr[i] ].push_front( arr[i] ); //要达到稳定排序，存和取必须从不同端
    }

    //收集结果
    size = 0;
    for(int i = 0; i <= range; ++i){
        while(!bin[i].empty()){
            arr[size++] = bin[i].back();    //取
            bin[i].pop_back();
        }
    }

    delete[] bin;
}

template<class T>
void _merge(T *a, int na, T* b, int nb, T* dest){
    int pa = 0, pb = 0, n = 0;
    
    while(pa < na && pb < nb){
        if(a[pa] < b[pb]){
            dest[n++] = a[pa++];
        }else{
            dest[n++] = b[pb++];
        }
    }
    
    while(pa < na) dest[n++] = a[pa++];
    while(pb < nb) dest[n++] = b[pb++];
}

template<class T>
void mergeSort(T *arr, int n){
    if(n <= 1){
        return;
    }
    
    int mid = n / 2;
    mergeSort(arr, mid);
    mergeSort(arr + mid, n - mid);
    
    T* temp = new T[n];
    _merge(arr, mid, arr + mid, n - mid, temp);
    
    for(int i = 0; i < n; ++i){
        arr[i] = temp[i];
    }
    
    delete[] temp;
}

// 对[l, r)进行快速排序
template<class T>
void quickSort(T* beginP, T* endP){
    if( beginP>=endP ) return;

    T* l = beginP;
    T* r = endP-1;
    T pivot = *beginP;
    
    while( l < r ){
        while( *r >= pivot && l<r ) r--;
        if( r==l ) break;
        *l = *r;

        while( *l <= pivot && l<r ) l++;
        if( r==l ) break;
        *r = *l;
    }

    *l = pivot;

    quickSort(beginP, l);
    quickSort(l+1, endP);
}

class MyData{
public:
    int x;
    int y;
    MyData(){
        x = rand();
        y = rand();
    }

    bool operator<(MyData o){
        return x < y;
    }
};

int main(){
    
    // MyData arr[5];
    // for(int i = 0; i < 5; ++i){
    //     cout << arr[i].x << "," << arr[i].y << endl;
    // }

    // // sort(arr, arr+5+1, 
    // //     [](MyData a, MyData b){
    // //         return a.x > b.x;
    // //     }
    // // );

    // mergeSort(arr, 5);

    // for(int i = 0; i < 5; ++i){
    //     cout << arr[i].x << "," << arr[i].y << endl;
    // }

    int arr[] = {5, 1, 6, 11, -1};
    quickSort(arr, arr+5);
    for(int i = 0; i < 5; ++i){
        cout << arr[i] << endl;
    }
    
    return 0;
}