class Solution {
public:
    bool winnerOfGame(string colors) {
        int alice=0;
        int bob=0;
        int count_1=0;
        int count_2=0;
        for(int i=0;i<colors.length();i++){
            if(colors[i]=='A')
                count_1++;
            else{
                if(count_1>=3)
                    alice+=count_1-3+1;
                count_1=0;
            }
            if(colors[i]=='B')
                count_2++;
            else{
                if(count_2>=3)
                    bob+=count_2-3+1;
                count_2=0;
            }
        }
        if(count_1>=3)
            alice+=count_1-3+1;
        if(count_2>=3)
            bob+=count_2-3+1;
        //cout<<alice<<" "<<bob;
        if(alice>=bob+1)
            return true;
        return false;
    }
};