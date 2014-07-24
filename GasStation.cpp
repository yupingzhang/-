//Gas Station 
/*There are N gas stations along a circular route, where the amount of gas at station i is gas[i].

You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from station i to its next station (i+1). You begin the journey with an empty tank at one of the gas stations.

Return the starting gas station's index if you can travel around the circuit once, otherwise return -1.

Note:
The solution is guaranteed to be unique.
*/

class Solution {
public:

    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        // at station i, if (cargas + gas[i] > cost[i]), then can reach the next station
        // pass N station meaning can travel around the circuit once
        // if i station is valid (can be reached), i-1 must be valid
        // if not valid, start from the next station, the worst case will go 2 circles
         
        int N = gas.size();
        int cargas = 0;    // empty
        int start = 0, count = 0;
        for(int i=0; i<2*N; i++) {
            if ( cargas + gas[i%N] >= cost[i%N]) { 
                cargas += gas[i%N]; 
                cargas -= cost[i%N];
                count++;
            }
            else { 
                cargas = 0; 
                count = 0;
                start = i + 1; 
            }
                
            if (count == N) // finish a circle
                return start; 
            
        }
        return -1;
    }
};
