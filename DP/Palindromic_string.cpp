class Solution{
    public:
        int expandaround(string& s , int left , int right)
        {
            int count = 0;
            while(left >=0 && right <s.size() && s[left] == s[right] )
            {
                count++;
                left--;
                right++;

            }
            return count;
        }


        int countStrings(string s)
        {
            int totalcount = 0;
            for(int i =0 ; i<s.size() ; i++)
            {
                totalcount += expandaround(s,i,i);
                totalcount += expandaround(s,i,i+1);
            }
            return totalcount;
            }
        
}