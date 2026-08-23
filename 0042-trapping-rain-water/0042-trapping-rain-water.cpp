class Solution {
  public:
    int trap(vector<int> &arr) {
        // code here
        int l =0;
        int r = arr.size()-1;
        
        int lMax = 0;
        int rMax = 0;
        
        int water = 0;
        
        while(l<r){
            // l chota hai r se toh left max se paani nikalo
            if(arr[l]<=arr[r]){
                if(arr[l]>lMax){
                    
                    lMax= arr[l];
                    
                } else{
                    
                    water += lMax - arr[l];
                }
                
                l++;
                // r chota hai l se toh right max se paani nikalo
            } else{
                
                if(arr[r]>rMax){
                    
                    rMax = arr[r];
                } else{
                    
                    water += rMax - arr[r];
                }
                
                r--;
            }
        }
        
        return water;
    }
};