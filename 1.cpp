class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        if(tokens.size() == 1)
            return stoi(tokens[0]);

        s.push(stoi(tokens[0]));
        s.push(stoi(tokens[1]));
        for(int i=2;i<tokens.size();++i){
            if(s.size() < 2){
                s.push(stoi(tokens[i]));
                continue;
            }
            int a = s.top();
            s.pop();
            int b = s.top();
            s.pop();
            
            string str = tokens[i];
            
            if(str == "+")
                s.push(a + b);
            else if(str == "-")
                s.push(b - a);
            else if(str == "*")
                s.push(trunc(a * double(b)));
            else if(str == "/"){
                s.push(trunc(double(double(b) / double(a))));
            }
            else{
                s.push(b);
                s.push(a);
                s.push(stoi(tokens[i]));
            }
        }
        return s.top();
    }
};
