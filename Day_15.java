

/* Problem Link: https://leetcode.com/explore/challenge/card/july-leetcoding-challenge/546/week-3-july-15th-july-21st/3391/
*/

class Solution {
    StringBuffer swapping(StringBuffer sb,int i,int j)
    {
        char a,b;
        while(i<j)
        {
            a=sb.charAt(i);
            b=sb.charAt(j);
            sb.setCharAt(j,a);
            sb.setCharAt(i,b);
            i++;
            j--;
        }
        return sb;
    }
    public String reverseWords(String s) {
        s=s.replaceAll("\\s+"," ").trim();
        Solution call=new Solution();
        StringBuffer sb=new StringBuffer(s);
        char a,b;
        int i,j,n;
        i=0;j=sb.length()-1;
        sb=call.swapping(sb,i,j);
        n=sb.length();
        j=0;
        for(i=0;i<n;i++)
        {
            if(sb.charAt(i)==' ')
            {
                sb=call.swapping(sb,j,i-1);
                j=i+1;
            }
        }
        sb=call.swapping(sb,j,i-1);
        return new String(sb);
    }
}