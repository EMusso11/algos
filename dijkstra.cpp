#include "dijkstra.h"
#include <vector>
#include <queue>
#define forall(it, v) for(auto it=v.begin(); it!=v.end(); it++)
#define sz(c) ((int)c.size())
#define INF 1e9

typedef pair<int, int> ii;

ll dijkstra(int start, int fin){
	priority_queue < ii, vector<ii>, greater<ii> > q;
	vector <ll> dist(MAXN, INF);
	
	q.push(make_pair(1, start)); dist[start]=0;
	
	while(sz(q)){
		ii p=q.top(); q.pop();
		if(p.second==fin) break;
		forall(it, g[p.second])
			if(dist[p.second]+it->first < dist[it->second]){			
			dist[it->second] = dist[p.second]+it->first;
			q.push(make_pair(dist[it->second], it->second));
		}
	}
	return dist[fin];
}	
