

/* Problem Link: https://leetcode.com/explore/challenge/card/july-leetcoding-challenge/544/week-1-july-1st-july-7th/3383/
*/

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int ans=0,i,j,r=grid.size();
        if(r==0) return 0;
        int c=grid[0].size();
        for(i=0;i<r;i++)
        {
            for(j=0;j<c;j++)
            {
                if(grid[i][j]==1)
                {
                    ans += 4;
                    if(i>0) ans -= grid[i-1][j];
                    if(i<r-1) ans -= grid[i+1][j];
                    if(j>0) ans -= grid[i][j-1];
                    if(j<c-1) ans -= grid[i][j+1];
                }
            }
        }
        return ans;
    }
};