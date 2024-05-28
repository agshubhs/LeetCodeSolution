class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        vector<int> countones;
        int count;
        for(int i = 0 ;i <bank.size();i++){
            count = 0;
            for(int j = 0; j < bank[i].length();j++){
                    if(bank[i][j]=='1')
                        count++;
            }
            if(count != 0)
                countones.push_back(count);
        }
        if(countones.size()==1)
            return 0;
        
        int res = 0;
        for(int i = 1 ;i<countones.size();i++){
            res += countones[i]*countones[i-1];
        }
        return res;


        
    }
};