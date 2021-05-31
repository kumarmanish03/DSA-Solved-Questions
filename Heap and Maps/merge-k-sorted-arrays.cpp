// Manish Kumar, IIIT Allahabad
// Medium
// Time Complexity : O(n*k*logk) 
// Space Complexity : O(n*k)

https://www.interviewbit.com/problems/merge-k-sorted-arrays/

// Since all arrays are already sorted, hence we use them to minimize complexity

// This soln also same if sizes of arrays are different

typedef pair<int, pair<int, int> > pi;

vector<int> Solution::solve(vector<vector<int> > &A) {
    vector<int> ans;
    // minHeap
    priority_queue<pi, vector<pi>, greater<pi>> pq;
    
    for(int i = 0; i < A.size(); i++){
        pq.push({A[i][0], {i, 0}});
    }
    
    while(pq.size() > 0){
        // This should be minimum from all
        pi minm = pq.top();
        pq.pop();
        // adding to answer
        ans.push_back(minm.first);
        
        int i = minm.second.first;
        int j = minm.second.second;
        if(j+1 < A[i].size()){
            pq.push({A[i][j+1], {i, j+1}});
        }
    }
    
    return ans;
}
