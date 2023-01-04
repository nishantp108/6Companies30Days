class Solution {
public:
    string getHint(string secret, string guess) {
        map<char, int> guess_map;
        map<char, int> bulls_map;

        int n = guess.size();
        int cows = 0,bulls =0;
        for(int i=0;i<n;++i){    
            if(guess[i] != secret[i])
                bulls_map[secret[i]]++;
            else
                bulls++;
        }
        for(int i=0;i<n;++i){
            if(guess[i] != secret[i]){
                auto it = bulls_map.find(guess[i]) ;
                if(it != bulls_map.end()){
                    if(bulls_map[guess[i]] != 0){
                        bulls_map[guess[i]]--;
                        cows++;
                    }
                }
            }
        }
        string res = "";
        res.append(to_string(bulls));
        res.append("A");
        res.append(to_string(cows));
        res.append("B");
        return res;
     
    }
};
