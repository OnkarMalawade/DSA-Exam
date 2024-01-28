#include<iostream>
#include<conio.h>
#define size 5
using namespace std;
class graph{
public:
    int i, j;
    int wt, u, v, edges;
    int graf[size][size];
    graph();
    void read(int, int, int);
    void display();
    void degree();
};
graph::graph() {
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            graf[i][j] = 0;
        }    }}
void graph::read(int u, int v, int wt) {
    graf[u][v] = wt;
    graf[v][u] = wt;  // Assuming it's an undirected graph
}
void graph::display() {
    cout << "\nGraph is:\n\n";
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            cout << "\t" << graf[i][j];
        }
        cout << endl << endl;
    }}
void graph::degree() {
    int in, out;
    cout << "\nIndegrees & outdegrees of vertices are:\n\n";
    for (i = 0; i < size; i++) {
        in = 0;
        out = 0;
        for (j = 0; j < size; j++) {
            if (graf[i][j] > 0) {
                in++;
            }
            if (graf[j][i] > 0) {
                out++;
            }        }
        cout << "Indegree of vertex " << i << " = " << in << endl;
        cout << "Outdegree of vertex " << i << " = " << out << endl << endl;
    }}
int main() {
    graph g;
    g.read(2, 3, 1);
    g.display();
    g.degree();
    getch();
    return 0;
}
