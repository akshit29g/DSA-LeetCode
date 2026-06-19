class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int altitude= 0;
        int maxi= 0;

        for (int x:gain){
            altitude+=x;
            maxi= max(maxi,altitude);
        }
        return maxi;
    }
};