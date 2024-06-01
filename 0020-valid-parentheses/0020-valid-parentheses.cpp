class Solution {
public:
    bool isValid(string s) { 
        int length = s.length();

        stack<char> c;
        for(int i =0; i<length;i++){
            if(s[i] == '(' || s[i] =='{' ||  s[i] == '[')
                c.push(s[i]);
            else{
                if(c.empty() == 1){   
                    return false;
                }
                if(s[i] ==  ')' && c.top()=='(' || s[i] ==  '}' && c.top()=='{' || s[i] ==  ']' && c.top()=='['){
                    c.pop();
                    continue;
                }
                else{
                    return false;
                }
                
            }
        }

        return c.empty()== 1 ? true : false;
        
    }
};