#include<iostream>
#include<vector>
#include<queue>

using namespace std;

vector<int> bfs(const vector<vector<int> >& adj_list, int start, int target = -1) {
    int n = adj_list.size();
    vector<bool> visited(n, false);
    vector<int> order;

    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        order.push_back(u);

        for (int i = 0; i < adj_list[u].size(); ++i) {
            int v = adj_list[u][i];
            if (!visited[v]) {
                q.push(v);
                visited[v] = true;
            }
        }
    }
    if (target != -1 && !visited[target]) {
        return {};
    }
    return order;
}

int main() {
    vector<vector<int> > adj_list;

    vector<int> row1 = [1, 2];
    vector<int> row2 = [0, 3, 4};
    vector<int> row3 = [0, 4};
    vector<int> row4 = [1, 4};
    vector<int> row5 = [1, 2, 3};

    adj_list.push_back(row1);
    adj_list.push_back(row2);
    adj_list.push_back(row3);
    adj_list.push_back(row4);
    adj_list.push_back(row5);

    vector<int> order = bfs(adj_list, 0);
    cout << "\nBFS traversal: ";
    for (int i = 0; i < order.size(); ++i) {
        cout << order[i] << " ";
    }
    cout << endl;
    return 0;
}

