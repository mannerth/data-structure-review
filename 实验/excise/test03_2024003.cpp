#include<iostream>
#include<queue>
#include<stack>
#include<vector>
#include<list>
#include<algorithm>
using namespace std;
list<int> a,b,c;
int arr[1000000], h = 0;
void print_list(list<int> l){
    if(l.size()==0){
        cout << "(nul)" << endl;
    }
    for(list<int>::iterator i = l.begin(); i != l.end(); ++i){
        cout << *i;
        if( i != --l.end() ) cout << ",";
        else cout << endl;
    }
}

void merge_list(){
    list<int>::iterator pa = a.begin();
    list<int>::iterator pb = b.begin();
    while(pa!=a.end() && pb!=b.end()){
        if( *pa < *pb){
            c.push_back(*pa);
            pa++;
        }else{
            c.push_back(*pb);
            pb++;
        }
    }
    while(pa!=a.end()){
        c.push_back(*pa);
        pa++;
    }
    while(pb!=b.end()){
        c.push_back(*pb);
        pb++;
    }
}

void insert_ordered( int x ){
    list<int>::iterator i = c.begin();
    while(i!=c.end()){
        if(x<*i){
            c.insert(i, x);
            return;
        }
        i++;
    }
    c.push_back(x);
}

void find_in_list(int x){
    list<int>::iterator i = c.begin();
    int cnt = 1;
    while(i!=c.end()){
        if( *i==x ){
            cout << cnt << endl; 
            return;
        }
        ++cnt;
        i++;
    }
    if(cnt==c.size()+1){
        cout << 0 << endl;
    }
}

void delete_target(int x){
    list<int>::iterator i = c.begin();
    while(i!=c.end()){
        if(*i==x){
            c.erase(i);
            return;
        }
        i++;
    }
}

void read_list(list<int>& the_list){
    int temp;
    cin >> temp;
    if(temp == 0){
        return;
    }
    the_list.push_back(temp);
    while(temp){
        cin >> temp;
        if(temp==0){
            break;
        }
        for( list<int>::iterator i = the_list.begin(); i != the_list.end(); i++ ){
            if( temp < *i ){
                the_list.insert( i, temp );
                break;
            }
            if( i == --the_list.end()){
                the_list.push_back(temp);
                break;
            }
        }
    }
}

int main(){
    cout << "Input1" << endl;
    read_list(a);
    cout << "Output1" << endl;
    print_list(a);

    cout << "Input2" << endl;
    read_list(b);
    cout << "Output2" << endl;
    print_list(b);  
    
    cout << "Mergence" << endl;
    merge_list();
    print_list(c);

    cout << "Insert" << endl;
    int toInsert;
    cin >> toInsert;
    cout << "Insertion" << endl;
    insert_ordered(toInsert);
    print_list(c);

    cout << "Delete" << endl;
    int toDe;
    cin >> toDe;
    cout << "Deletion" << endl;
    delete_target(toDe);
    print_list(c);

    cout << "Find" << endl;
    int toFind;
    cin >> toFind;
    cout << "Position" << endl;
    find_in_list(toFind);

    cout << "End" << endl;
    return 0;
}