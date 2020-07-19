

/* Problem Link: https://leetcode.com/explore/challenge/card/july-leetcoding-challenge/546/week-3-july-15th-july-21st/3395/
*/


class Solution {
public:
    string addBinary(string a, string b) {
        int len1,len2,i,n1,n2,c=0;
        len1=a.size();
        len2=b.size();
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
        string ans="";
        for(i=0;i<min(len1,len2);i++)
        {
            n1=(a[i]-'0');
            n2=(b[i]-'0');
            n1 += n2;
            n1 += c;
            ans += to_string(n1%2);
            c = n1/2;
        }
        if(len1>len2)
        {
            for(;i<len1;i++)
            {
                n1=(a[i]-'0');
                n1 += c;
                ans += to_string(n1%2);
                c = n1/2;
            }
            if(c > 0) ans += to_string(c);
        }
        else
        {
            for(;i<len2;i++)
            {
                n2=(b[i]-'0');
                n2 += c;
                ans += to_string(n2%2);
                c = n2/2;
            }
            if(c > 0) ans += to_string(c);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};