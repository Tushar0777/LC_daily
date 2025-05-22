//approach-1
class Solution {
public:
    typedef long long ll;
    vector<long long> findMaxSum(vector<int>& nums1, vector<int>& nums2, int k) {
        
        int n = nums1.size();

        vector<ll> result(n, 0);

        //O(n * ((nlogk) + (klogk)))
        for(int i = 0; i < n; i++) { //O(n)
            priority_queue<int, vector<int>, greater<int>> pq;
            for(int j = 0; j < n; j++) { //O(n * log(k))
                if(nums1[j] < nums1[i]) {
                    //jth index is the valid candidate
                    //Find the element in nums2 at jth index
                    pq.push(nums2[j]); //O(log(k))
                    if(pq.size() > k) {
                        pq.pop(); //O(log(k))
                    }
                }
            }

            long long sum = 0;
            while(!pq.empty()) { //K
                sum += pq.top();
                pq.pop(); //O(logk)
            }

            result[i] = sum;
        }

        return result;
    }
};



