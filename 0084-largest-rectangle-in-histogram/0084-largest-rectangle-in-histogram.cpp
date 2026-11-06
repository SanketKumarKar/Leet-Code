class Solution {
  public:
    int largestRectangleArea(vector<int> &arr) {
        
        int n  = arr.size();
        int maxArea = INT_MIN;
        stack<int> st;
        
        for(int i = 0 ; i < n ; i++){ //while traversing curr elt nse for some big bar and pse is 
                                      // uske big bar ke phele wala elt
            while(!st.empty() && arr[st.top()]>=arr[i]){
                int nse = i;
                int h = arr[st.top()];
                st.pop();
                int pse = st.empty()? -1 : st.top();
                int w = nse - pse - 1;
                
                maxArea = max(maxArea , h*w);
            }
            
            st.push(i);
        }
        
        while(!st.empty()){ //rem elt ke koi nse nhi hai thats why they are left in stack
            int h = arr[st.top()];
            int nse = n;
            st.pop();
            int pse = st.empty() ? -1 : st.top();
            int w = nse - pse - 1;
            maxArea = max(maxArea, h*w);
        }
        
        return maxArea;
    }
};
