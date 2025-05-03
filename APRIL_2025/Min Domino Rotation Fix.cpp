// in this we first have to chek if the element on top half
// if it is top or we have to swap it to make it bottom+1

// similarly for bottom we do the same 

class Solution {
public:
    int check(int x,vector<int>& tops, vector<int>& bottoms){
        int topcount=0;
        int bottomcount=0;

        for(int i=0;i<tops.size();i++){
            if(tops[i]!=x && bottoms[i]!=x){
                return -1;

            }
            if(tops[i]!=x){
                bottomcount++;
            }
            if(bottoms[i]!=x){
                topcount++;
            }
        }
        return(min(topcount,bottomcount));
    }
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
      int tp=check(tops[0],tops,bottoms);
        if(tp!=-1){
            return tp;
        }
        else{
            return check(bottoms[0],tops,bottoms);
        }
    }
};

