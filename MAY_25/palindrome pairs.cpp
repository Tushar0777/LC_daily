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
