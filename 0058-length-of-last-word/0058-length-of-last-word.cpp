class Solution {
public:
    int lengthOfLastWord(string s) {
        ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

        int len=0;
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]==' '){
                if(len>0)return len;
            }
            else len++;
        }
        return len; 
    }
};