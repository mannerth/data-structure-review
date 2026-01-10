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

class MyData{
    
public:
    int x;
    int y;
    MyData(){
        x = rand();
        y = rand();
    }
};

int main(){
    
    MyData arr[5];
    for(int i = 0; i < 5; ++i){
        cout << arr[i].x << "," << arr[i].y << endl;
    }

    sort(arr, arr+5+1, 
        [](MyData a, MyData b){
            return a.x > b.x;
        }
    );

    for(int i = 0; i < 5; ++i){
        cout << arr[i].x << "," << arr[i].y << endl;
    }
    
    return 0;
}