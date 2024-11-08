class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) 
    {
        int left =0;
        int right = matrix[0].size() -1;
        int top = 0;
        int bottom = matrix.size() -1;
        int diraction = 0;
        vector<int>ans;
        while(left <= right && top <=bottom)
        {
            if(diraction == 0)
            {
                for(int cols= left ; cols<=right;cols++)
                {
                    ans.push_back(matrix[top][cols]);
                }
                    top++;
            }
            if(diraction ==1)
            {
            for(int row =top;row<=bottom;row++)
            {
            
                ans.push_back(matrix[row][right]);
            }
                    right--;
            }
            if(diraction == 2)
            {
                for(int cols= right;cols>=left;cols--)
                {
                    ans.push_back(matrix[bottom][cols]);
                }
                    bottom--;
            }
            if(diraction ==3)
            {
            for(int row =bottom;row>=top;row--)
            {
                ans.push_back(matrix[row][left]);
            }
                    left++;
            }
            diraction  =(diraction+1)%4;
        }
        return ans;
    }  

};