//subsets II
/*
Given a collection of integers that might contain duplicates, S, return all possible subsets.

Note:
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
For example,
If S = [1,2,2], a solution is:

[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]
*/

class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        sort(S.begin(), S.end());
        vector<vector<int> > result;
        vector<int> sset;
        // add empty subset
        result.push_back(sset);
        int size = S.size();
        if(size == 0) return result;
        sset.push_back(S[0]);
        result.push_back(sset);
        //In sum up, when meet the same element as previous one, 
        //then generate new subsets ONLY from the subsets generated from previous iteration, other than the whole subsets list.
        //when n=1, subsets :  {}, {"1"},
        //when n=2, subsets:   {}, {"1"}, || {"2"}, {"1", "2"}
        //when n(3)=2, ---->   {}, {"1"}, {"2"}, {"1", "2"}, ||  {"2","2"}, {"1", "2","2"} 
        
        int pre = S[0];
        int count = 1;
        for (int i=1;i<S.size();i++){
            int st=0;                          // if it's a new element, start from beginning
            int sz = result.size();
            if (S[i]==pre) {st = sz-count;}     // count == the subsets generated from previous iteration
            count = 0;             
            for (int j=st;j<sz;j++){   // st = start index of subset in the result that new subsets should generate from
              sset = result[j];
              sset.push_back(S[i]);
              result.push_back(sset);
              count++;
            }
            pre=S[i];
        }
   
        return result;
    }
};
