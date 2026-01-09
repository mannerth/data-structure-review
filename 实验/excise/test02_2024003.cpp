#include<iostream>
#include<vector>
#include<list>
using namespace std;

void bubble_sort(int *arr, int n){
    for(int i = n; i >= 1; --i){
        for(int j = 1; j < i; ++j){
            if(arr[j]>arr[j+1]){
                swap(arr[j], arr[j+1]);
            }
        }
    }
    for(int i = 1; i <= n; ++i){
        cout << arr[i];
        if(i!=n) cout << ",";
        else cout << endl;
    }
}

void insert_sort(int *arr, int n){// 5 6 1 9
    vector<int> v;
    v.push_back(0);
    v.push_back(arr[1]);
    for(int i = 2; i <= n; ++i){
        for(int j = 1; j <= i; ++j){
            if( arr[i] < v[j] || i == j){
                v.insert(v.begin()+j, arr[i]);
                break;
            }
        }
    }

    for(int i = 1; i <= n; ++i){
        cout << v[i];
        if(i!=n) cout << ",";
        else cout << endl;
    }
}

void select_sort(int *arr, int n){
    for(int i = 1; i < n; ++i){
        int tIdx = i;
        for(int j = i; j <= n; ++j){
            if(arr[j]<arr[tIdx]){
                tIdx = j;
            }
        }
        swap(arr[i], arr[tIdx]);
    }

    for(int i = 1; i <= n; ++i){
        cout << arr[i];
        if(i!=n) cout << ",";
        else cout << endl;
    }
}

int main(){
    cout << "Input" << endl;
    int a[20], n=0;
    while(cin >> a[++n]){
        if(a[n]==0){
            n--;
            break;
        }
        if(n==18) break;
    }
    
    cout << "1-Bubble Sort,2-Insert Sort,3-Select Sort" << endl;
    int opt;
    cin >> opt;

    cout << "Output" << endl;
    switch (opt)
    {
    case 1:
        cout << "Bubble Sort" << endl;
        bubble_sort(a, n);
        break;
    case 2:
        cout << "Insert Sort" << endl;
        insert_sort(a, n);
        break;
    case 3:
        cout << "Select Sort" << endl;
        select_sort(a, n);
        break;
    default:
        break;
    }

    cout << "End" << endl;
    return 0;
}