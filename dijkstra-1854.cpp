// k번째 최단경로(다익스트라)
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
#include <cstring>
 
using namespace std;
 
int n, m, k, from, to, cost, Start;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
priority_queue<int> city[1001];
vector<pair<int, int> > v[1001];
 
void dijkstra()
{
   pq.push(make_pair(0, 1));
   city[1].push(0);
 
   while (!pq.empty()){
       int cur = pq.top().second;
       int num = pq.top().first;
       pq.pop();
 
        for (int i=0; i<v[cur].size(); i++){
            int next = v[cur][i].first;
            int nextCost = num + v[cur][i].second;
            if (city[next].size()<k){
                city[next].push(nextCost);
                pq.push(make_pair(nextCost, next));
            } else {
                if (city[next].top()>nextCost){
                    city[next].pop();
                    city[next].push(nextCost);
                    pq.push(make_pair(nextCost, next));
                }
            }
        }
   }
}
 
 
int main()
{
    cin>>n>>m>>k;
    for (int i=0; i<m; i++){
        cin>>from>>to>>cost;
        v[from].push_back(make_pair(to, cost));
    }
 
    dijkstra();
 
    for(int i=1; i<=n; i++){
        if (city[i].size()<k){
            cout<<"-1"<<"\n";
        } else{
            cout<<city[i].top()<<"\n";
        }
    }
 
    return 0;
}

