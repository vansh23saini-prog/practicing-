class Solution {
public:
    bool detectCapitalUse(std::string word) { 
     
        if (word.size() <= 1) return true;

        for (int i = 1; i < word.size(); i++) { 
            if (isupper(word[1]) != isupper(word[i]) || islower(word[0]) && isupper(word[i])) 
                return false; 
        } 
        return true;
    }
};