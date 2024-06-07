class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        int n = dictionary.size();
        set<string> dict;
        for(int i = 0 ; i<n;i++){
            dict.insert(dictionary[i]);
        }
        stringstream s(sentence);
        string word;
        string ans;
        while(s>>word){
            string temp = "";
            for(int i  = 0; i<word.length();i++){
                temp = temp + word[i];
                // cout<<t
                if(dict.find(temp) != dict.end()){
                    break;
                }
            }
            ans += temp +' ';            
        }

        return ans.substr(0, ans.length()-1);
    }
};