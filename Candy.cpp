//Candy 
/*There are N children standing in a line. Each child is assigned a rating value.

You are giving candies to these children subjected to the following requirements:

Each child must have at least one candy.
Children with a higher rating get more candies than their neighbors.
What is the minimum candies you must give?
*/
// find the min/max in ratings and distance between  

class Solution {
public:
    int candy(vector<int> &ratings) {
        int n = ratings.size();
        int min_candies = n;

        int range = 0;
        for (size_t i = 0; i < n - 1; ) {
            int start = i;
            while (ratings[i] < ratings[i+1] && i < n-1) ++i;   // i would reach the peak
            range = i - start;
            min_candies += (range * (range + 1)) / 2;           // add extra candies until i
            if (i == n-1) break;

            start = i;
            while (ratings[i] > ratings[i+1] && i < n-1) ++i;
            int k = i - start - 1;                              // leave the last one because it can be 1 (min)
            min_candies += (k * (k + 1)) / 2;
            if (i - start > range) min_candies += (i - start - range);   // Need to add extra if this side has more!!!
            if (ratings[i] == ratings[i+1]) ++i;                // equre/no more than the neighbors --> 1 (min)
        }
        return min_candies;
    }
};
