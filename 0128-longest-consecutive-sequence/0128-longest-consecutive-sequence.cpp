class Solution {
public:
    int longestConsecutive(vector<int>& arr) {
        unordered_set<int> st(arr.begin(), arr.end());
        int longest = 0;
        for(int x : st){

            if(st.find(x-1)==st.end()){// start of sequence identify krre hai
                int count = 1;
                int curr = x;                
            

                while(st.find(curr+1)!= st.end()){
                    curr +=1;
                    count +=1;
                }
            
            longest = max(count,longest);
            }
        }

        return longest;
    }
};