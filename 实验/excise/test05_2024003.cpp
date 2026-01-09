#include<iostream>
#include<stack>
using namespace std;
#include<string>

template< class T >
class stk{

private:
    int p;
    int cap;
    T* data;
public:
    stk(int s);
    ~stk();
    bool empty(){return p==0;}
    bool isNotEmpty(){return p!=0;}
    int size(){return p;}
    void push(const T& val){
        data[++p] = val;
    }
    //data[0]不放数据
    void pop(){
        if(p!=0)
            p--;
    }
    T top() const{
        if(p==0) return 0;
        return data[p];
    }

};
template< class T >
stk<T>::stk(int s){
    cap = s;
    data = new T[s];
    p = 0;
}
template< class T >
stk<T>::~stk(){
    delete data;
}

stk<int> nums(100);
stk<char> op (100);

int calculate(char opt, int x, int y){
    switch(opt){
        case '+':
            return x+y;
            break;
        case '-':
            return y - x;
            break;
        case '*':
            return x*y;
            break;
        case '/':
            return y/x;
            break;
    }
    return 0;
}

int main(){
    cout << "Input" << endl;
    string s;
    cin >> s;
    cout << "Output" << endl;
    //5 + 3*(5/2)
    /*
    11
     
    */
    
    for(int i = 0; i < s.length(); ++i){
        if( s[i] >= 48 && s[i]<=57 ){
            int temp = s[i]-'0';
            nums.push( temp );
        }else{
            char o = s[i];
            switch(o){
                case '+':
                case '-':
                    while(!op.empty() && op.top()!='(' && nums.size()>=2){
                        char opt = op.top();
                        op.pop();
                        int x = nums.top();
                        nums.pop();
                        int y = nums.top();
                        nums.pop();
                        nums.push( calculate(opt, x, y) );
                    }
                    op.push( o );
                    break;
                case '*':
                case '/':
                    if(op.top()=='*'||op.top()=='/'){
                        char opt = op.top();
                        op.pop();
                        int x = nums.top();
                        nums.pop();
                        int y = nums.top();
                        nums.pop();
                        nums.push( calculate(opt, x, y) );
                    }
                    op.push(o);
                    break;
                case '(':
                    op.push(o);
                    break;
                case ')':
                    while(!op.empty()&&op.top()!='('){
                        char opt = op.top();
                        op.pop();
                        if(opt=='('){
                            break;
                        }
                        int x = nums.top();
                        nums.pop();
                        int y = nums.top();
                        nums.pop();
                        nums.push( calculate(opt, x, y) );
                    }
                    if (!op.empty() && op.top() == '(') {
                        op.pop();
                    }
                    break;
            }
        }
    }
    while(!op.empty()){
        char opt = op.top();
        op.pop();
        int x = nums.top();
        nums.pop();
        int y = nums.top();
        nums.pop();
        nums.push( calculate(opt, x, y) );
    }
    cout << "=" << nums.top() << endl;
    cout << "End" << endl;
    return 0;
}