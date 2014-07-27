// Clone Graph
// Clone an undirected graph. Each node in the graph contains a label and a list of its neighbors.

/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
// deep copy and dfs
// use hash map to store copied nodes in the clone graph
// if the node has been visited, just add the map[int] to the current node's neighbor list, otherwise copy this new node

typedef unordered_map< int, UndirectedGraphNode *> Map;

class Solution {
public:
    
    UndirectedGraphNode *dfs(UndirectedGraphNode *graph, Map &copied) {
        UndirectedGraphNode *res = new UndirectedGraphNode(graph->label);
        copied[graph->label] = res;
       
        if(graph->neighbors.size() != 0) {
            for(vector<UndirectedGraphNode *>::iterator it = graph->neighbors.begin(); it != graph->neighbors.end(); it++) {
                if(copied.find((*it)->label) == copied.end()) // if not in the hash map ==> haven't copy
                {
                    res->neighbors.push_back(dfs(*it, copied));
                } else {  // add the pointer to the neighbors vector
                    res->neighbors.push_back(copied[(*it)->label]);
                }
            }
        }
        return res;
    }
    
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        UndirectedGraphNode *result;
        if(node == NULL) {
            return NULL;
        }else {
            Map copied;
            result = dfs(node, copied);
            return result;
        }
    }
};
