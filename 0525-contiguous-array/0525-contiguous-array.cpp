class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int>mp;
        int maxi=0,count=0;
        mp[0]=-1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1)count++;
            else count--;
            if(mp.find(count) != mp.end()){
                int len = i-mp[count];
                maxi = max(maxi,len);
            }
            else mp[count]=i;
        }
        return maxi;
    }
};