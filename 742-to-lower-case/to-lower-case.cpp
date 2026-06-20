class Solution {
public:
    string toLowerCase(string s) { // function used tolower()
        string ans=""; //empty string 
        for(int i=0;i<s.size();i++){ //read char by char 
          ans+=tolower(s[i]);
        }
        return ans;
    }
};

