class Solution {
public:
    bool isPalindrome(string combined){
        int left=0;
        int right=combined.size()-1;

        while(right>=left){
            if(combined[left]!=combined[right]){
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>>result;
        unordered_map<string,int>freq;

        int n=words.size();
        for(int i=0;i<n;i++){

            //words[i] ke liye ab sab ke sath add krke dekh 

            string word=words[i];
            for(int j=0;j<n;j++){
                if(i==j) continue;

                string combine=word+words[j];
                if(isPalindrome(combine)){
                    vector<int>temp;
                    temp.push_back(i);
                    temp.push_back(j);
                    result.push_back(temp);
                }
            }

        }
        return result;
        
    }
};




// trie wala implementation 



class Solution {
public:
    bool isPalindrome(string combined){
        int left=0;
        int right=combined.size()-1;

        while(right>=left){
            if(combined[left]!=combined[right]){
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>>result;

        unordered_map<string,int>freq;

        int n=words.size();

        for(int i=0;i<n;i++){
            freq[words[i]]=i;
        }
        if (freq.count("")) {
            int emptyIndex = freq[""];
            for (int i = 0; i < n; i++) {
                if (i == emptyIndex) continue;
                if (isPalindrome(words[i])) {
                    result.push_back({emptyIndex, i});
                    // result.push_back({i, emptyIndex});
                }
            }
        }

        for(int i=0;i<n;i++){
            string word=words[i];
            string rev=word;
            reverse(rev.begin(),rev.end());

            int len=word.size();

            for(int j=0;j<len;j++){
                string prefix=word.substr(0,j);
                string suffix=word.substr(j);

                if(isPalindrome(prefix)){
                    string revsuffix=suffix;
                    reverse(revsuffix.begin(),revsuffix.end());
                    if(freq.count(revsuffix) && freq[revsuffix]!=i){
                        result.push_back({freq[revsuffix],i});
                    }
                }
                if(j!=len && isPalindrome(suffix)){
                    string revprefix=prefix;
                    reverse(revprefix.begin(),revprefix.end());

                    if(freq.count(revprefix)&&freq[revprefix]!=i){
                        result.push_back({i,freq[revprefix]});
                    }
                }
            }

        }
        return result;
        
    }
};


