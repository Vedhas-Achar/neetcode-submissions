class Solution {
public:
    bool topo(vector<vector<int>>& prereq, int numCourses) {

        vector<vector<int>> adj(numCourses);
        vector<int> indeg(numCourses, 0);

        for (auto c : prereq) {
            adj[c[1]].push_back(c[0]);
            indeg[c[0]]++;
        }

        queue<int> q;

        for (int i = 0; i < numCourses; i++) {
            if (indeg[i] == 0)
                q.push(i);
        }

        int count = 0;

        while (!q.empty()) {
            int c = q.front();
            q.pop();

            count++;

            for (int next : adj[c]) {
                indeg[next]--;

                if (indeg[next] == 0)
                    q.push(next);
            }
        }

        return count == numCourses;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        return topo(prerequisites, numCourses);
    }
};