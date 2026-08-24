class Solution {
  public:
    int maxArea(vector<int> &arr) {
        //cal dist * min of l and r // agar l bada hai toh r-- else l++ 
        if(arr.size()<2){
            return 0;
        }
        // code here
        int dist;
        int l = 0;
        int r = arr.size()-1;
        int water =0;
        
        while(l<r){
            dist = r-l;
            water = max(water, min(arr[l],arr[r])*dist);
            
            if(arr[l]<arr[r]){
                l++;
            }else{
                r--;
            }
            
        }
        return water;
    }
};