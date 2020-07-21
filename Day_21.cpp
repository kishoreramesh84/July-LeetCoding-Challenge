

/* Problem Link: https://leetcode.com/explore/featured/card/july-leetcoding-challenge/546/week-3-july-15th-july-21st/3397/
*/


class Solution {
    int rows,columns;
public:
    struct Trie{
        bool end;
        struct Trie *child[128];
    };
    typedef struct Trie Node;
    Node *newnode()
    {
        Node *ne=new Trie;
        ne->end=false;
        for(int i=0;i<128;i++)
            ne->child[i]=NULL;
        return ne;
    }
    Node*create(string w)
    {
        Node *r=newnode();
        Node *trav=r;
        for(int i=0;i<w.size();i++)
        {
            if(trav->child[w[i]]==NULL)
                trav->child[w[i]]=newnode();
            trav=trav->child[w[i]];
        }
        trav->end=true;
        return r;
    }
    bool solve(vector<vector<char>>&board,int x,int y,Node *r)
    {
        if(r->end==true) return true;
        if(x<0 or x>=rows or y<0 or y>=columns or board[x][y]=='&')
            return false;
        if(r->child[board[x][y]])
        {
            char tmp=board[x][y];
            board[x][y]='&';
            if(x+1 < rows and solve(board,x+1,y,r->child[tmp]))
                return true;
            if(x-1 >=0 and solve(board,x-1,y,r->child[tmp]))
                return true;
            if(y+1 < columns and solve(board,x,y+1,r->child[tmp]))
                return true;
            if(y-1 >=0 and solve(board,x,y-1,r->child[tmp]))
                return true;
            board[x][y]=tmp;
        }
        if(r->child[board[x][y]] and r->child[board[x][y]]->end) return true;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        Node *root;
        root=create(word);
        rows=board.size();
        columns=board[0].size();
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<columns;j++)
            {
                if(root->child[board[i][j]])
                {
                    if(solve(board,i,j,root)) return 1;
                }
            }
        }
        return 0;
    }
};