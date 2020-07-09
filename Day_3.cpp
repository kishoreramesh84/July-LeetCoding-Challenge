

/* Problem Link: https://leetcode.com/explore/challenge/card/july-leetcoding-challenge/544/week-1-july-1st-july-7th/3379/
*/

class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int N) {
        unordered_map<string,int>mp;
        for(int i=0;i<N;i++)
        {
            string s(cells.begin(),cells.end());
            if(mp.find(s)!=mp.end())
            {
                int l=mp[s];
                int length=abs(l-i);
                return prisonAfterNDays(cells,(N-i)%length);
            }
            else
            {
                mp[s]=i;
                vector<int>tmp=cells;
                for(int j=1;j<7;j++)
                {
                    if(cells[j-1]==cells[j+1])
                    {
                        tmp[j]=1;
                    }
                    else
                    {
                        tmp[j]=0;
                    }
                }
                tmp[0]=0;
                tmp[7]=0;
                cells=tmp;
            }
        }
        return cells;
    }
};