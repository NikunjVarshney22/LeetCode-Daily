// class Solution {
// public:
//     vector<int> smallestRange(vector<vector<int>>& nums) {
     
//      pair<int ,pair<int, int>>
//   priority_queue< pair<int ,pair<int, int>>,vector<pair<int ,pair<int, int>>>,greater< pair<int ,pair<int, int>>>>p;
         
//         int minimum ,  maximum = INT_MIN;
//         for( int i = 0 ; i<nums.size() ; i++){
//             p.push(make_pair(nums[i][0] , make_pair(i,0)));
            
//             maximum = max( maximum , nums[i][0]);
//         }
//         minimum = p.top().first;
//         vector<int>ans(2);
//         ans[0]=minimum ;
//         ans[1] = maximum;
        
//         pair<int , pair<int, int>>temp;
//         int row , column  , element;
        
//         while(p.size()==nums.size()){
//             temp = p.top();
//             p.pop();
            
//             element = temp.first;
//             row =  temp.second.first;
//             column = temp.second.second;
            
//             if( col+1 < nums[row].size())
//             {
//                 col++;
                 
//                 p.push(make_pair(nums[row][col] , make_pair(row ,column)))
                    
//   maximum = max( maximum , nums[row][column]);
//                 minimum = p.top().first;
                
//                 if(maximum -minimum < ans[1]-ans[0])
                    
//                 {
//                     ans[0]= minimum ;
//                     ans[1]=maximum;
//                 }
//             }
//         }
//         return ans;
        
//     }
// };
class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        vector<int> ans;
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        int minElement, maxElement = INT_MIN;
        for(int i=0;i<nums.size();i++){
            pq.push({nums[i][0],{i,0}});
            maxElement = max(maxElement,nums[i][0]);
        }
        minElement = pq.top().first;
        ans = {minElement,maxElement};
        while(pq.size() == nums.size()){
            int minRangeVal = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            pq.pop();
            if(col+1 < nums[row].size()){
                pq.push({nums[row][col+1],{row,col+1}});
                maxElement = max(maxElement,nums[row][col+1]);
                minElement = pq.top().first;
            }
            if(maxElement - minElement < ans[1] - ans[0]){
                ans[0] = minElement;
                ans[1] = maxElement;
            }
        }
        return ans;
    }
};