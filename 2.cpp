class Solution {
public:
    void call(int index, vector<int> &inp,int sum, int k, int n, vector<int> &dump,     vector<vector<int>> &res){
        
        if(sum == n && dump.size() == k){
            res.push_back(dump);
            return;
        }else if(index == n)
            return;
        
        for(int i=index;i<min(n,10);++i){

            dump.push_back(inp[i]);
            call(i+1, inp, sum + inp[i], k, n, dump, res);
            dump.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int> > res;
        vector<int> inp{0,1,2,3,4,5,6,7,8,9};
        vector<int> dump;
        call(1, inp, 0, k, n, dump, res);
        return res;
    }
};
