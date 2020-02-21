#include <iostream>
#include <stack>
using namespace std;
int balancedStringSplit(string s) {
    int ans = 0;
    stack<char> tempStack;
    for(int cnt = 0; cnt < s.length(); cnt++){
        if(tempStack.empty()){
            tempStack.push(s[cnt]);
        }else if(tempStack.top() != s[cnt]){
            tempStack.pop();
            if(tempStack.empty()){
                ans += 1;
            }
        }else{
            tempStack.push(s[cnt]);
        }
    }
    return ans;
}
int main(){
    string input = "RLRRLLRLRL";
    cout << balancedStringSplit(input) << endl;
    return 0;
}
