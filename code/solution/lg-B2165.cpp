#include<iostream>
#include<stack>
#include<string>
using namespace std;

int n;

int main(){
    cin >> n;
    while(n--){
        stack<char> stk;
        string s;
        cin >> s;

        if(s.length()%2){
            cout << "NO" << endl;
            continue;
        }

        bool vaild = true;

        for(int i = 0; i < s.length(); ++i){
            char c = s[i];
            switch (c){
                case '[':
                    stk.push(c);
                    break;
                case ']':
                    if(stk.empty() || stk.top()!='['){
                        vaild = false;
                        break;
                    }
                    stk.pop();
                    break;
                case '(':
                    stk.push(c);
                    break;
                case ')':
                    if(stk.empty()||stk.top()!='('){
                        vaild = false;
                        break;
                    }
                    stk.pop();
                    break;
                case '{':
                    stk.push(c);
                    break;
                case '}':
                    if(stk.empty()||stk.top()!='{'){
                        vaild = false;
                        break;
                    }
                    stk.pop();
                    break;
                
                default:
                    break;
            }
            if(!vaild){
                break;
            }
        }
        if( !stk.empty() ){
            vaild = false;
        }
        cout << (vaild? "YES" : "NO") << endl;
    }

    return 0;
}