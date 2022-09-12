class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(),tokens.end());
        int l = 0;
        int h = tokens.size()-1;
        int score = 0;
        int maxScore = 0;
        while(l <= h){
            if(power >= tokens[l]){
                power -= tokens[l];
                score++;
                l++;
            }
            else if(score >= 1){
                power += tokens[h];
                h--;
                score--;
            }
            else
                break;
            maxScore = max(maxScore,score);
        }
        return maxScore;
    }
};