#include<bits/stdc++.h>
using namespace std;

class Graph{
	private:
		map<string,list<pair<string,int> > >graph;
	public:
		void addEdge(string src,string dest,int val);
		void removeEdge(string s1,string s2);
		void display_map();
		void display_stations();
		bool hasPath(string src,string dest);
		int get_minimum_dist(string src,string dest);getsg
		vector<string> get_shortest_path(string src,string dest);
};

void Graph::addEdge(string station1,string station2,int price){
	graph[station1].push_back({station2,price});
	graph[station2].push_back({station1,price});
}
void Graph::removeEdge(string station1,string station2){
	if(graph.find(station1)!=graph.end())graph.erase(graph.find(station1));
	if(graph.find(station2)!=graph.end())graph.erase(graph.find(station2));
}
void Graph::display_map(){
	cout<<"\t Patna Metro Map\n";
	cout<<"\t------------------\n";
	cout<<"-------------------------------\n";
	for(auto vertices:graph){
		string str= vertices.first+" =====> ";
		for(auto neighbour:vertices.second){
			str=str+ "\t" + neighbour.first + "\t";
			if(neighbour.first.size()<16)
			 str= str + "\t";
			if(neighbour.first.size()<8)
			 str= str + "\t";
		}
		cout<<str<<"\n"<<endl;
	}
	cout<<"\t------------------\n";
	cout<<"-------------------------------------------------------\n";
	
}
void Graph::display_stations(){
	cout<<"\n***********************************************************************\n"<<endl;
	 int i=1;
     for(auto stations:graph){
		cout<<i<<". "<<stations.first<<endl;
		i++;
	 }
	cout<<"\n***********************************************************************\n"<<endl;
}
bool Graph::hasPath(string src,string dest){
	queue<string>q;
	unordered_map<string,bool>visited;
	q.push(src);
	bool path=false;
	visited[src]=true;
	while(!q.empty()){
		auto curr=q.front();q.pop();
		if(curr==dest){path=true;break;}
		for(auto neigh:graph[curr]){
			if(!visited[neigh.first]){
				q.push(neigh.first);
				visited[neigh.first]=true;
			}
		}
	}
	return path;
}
int Graph::get_minimum_dist(string src,string dest){
	unordered_map<string,int>dist;
	unordered_map<string,bool>vis;
	const inf=1e9;
	for(auto stations:graph){
		Cost[stations.first]=inf;
	}
	dist[src]=0;
	set<pair<int,string>>st;
	vis[src]=true;
	st.insert({0.src});
	while(!st.empty()){
          auto curr= *(st.begin());
		  st.erase(st.find(st.begin()));
		  int station=curr.second;
		  if(vis[station])continue;
		  vis[station]=true;
		  for(auto neigh:graph[station]){
			 int neigh_cost=neigh.second;
			 int neigh_vext=neigh.first;
			 if(dist[station]+neigh_cost < dist[neigh_vext]){
				dist[neigh_vext]=dist[station]+neigh_cost;
				st.insert({dist[neigh_vext],neigh_vext});
			 }
		  }

	}
    return dist[dest];
}

int main(){
	Graph g=Graph();
	g.addEdge("Noida Sector 62~B", "Botanical Garden~B", 8);
	g.addEdge("Botanical Garden~B", "Yamuna Bank~B", 10);
	g.addEdge("Yamuna Bank~B", "Vaishali~B", 8);
	g.addEdge("Yamuna Bank~B", "Rajiv Chowk~BY", 6);
	g.addEdge("Rajiv Chowk~BY", "Moti Nagar~B", 9);
	g.addEdge("Moti Nagar~B", "Janak Puri West~BO", 7);
	g.addEdge("Janak Puri West~BO", "Dwarka Sector 21~B", 6);
	g.addEdge("Huda City Center~Y", "Saket~Y", 15);
	g.addEdge("Saket~Y", "AIIMS~Y", 6);
	g.addEdge("AIIMS~Y", "Rajiv Chowk~BY", 7);
	g.addEdge("Rajiv Chowk~BY", "New Delhi~YO", 1);
	g.addEdge("New Delhi~YO", "Chandni Chowk~Y", 2);
	g.addEdge("Chandni Chowk~Y", "Vishwavidyalaya~Y", 5);
	g.addEdge("New Delhi~YO", "Shivaji Stadium~O", 2);
	g.addEdge("Shivaji Stadium~O", "DDS Campus~O", 7);
	g.addEdge("DDS Campus~O", "IGI Airport~O", 8);
	g.addEdge("Moti Nagar~B", "Rajouri Garden~BP", 2);
	g.addEdge("Punjabi Bagh West~P", "Rajouri Garden~BP", 2);
	g.addEdge("Punjabi Bagh West~P", "Netaji Subhash Place~PR", 3);
	while(1){
		int choice;
		cout<<"1.To display map \n";
		cout<<"2.To display station\n";
		cout<<"3. To your their is path between two station\n";
		cout<<"4.To your shortest distance between two station\n";
		cout<<"-1. To exit\n";
		cout<<"enter your choice \n";
		cin>> choice ;
		if(choice==-1) break;
		switch(choice){
			case 1: g.display_map();
				break;
				
			case 2 :g.display_stations();
				break;
				
			case 3 :string source,destination;
				g.display_stations();
				cout<<"please enter stations name from given stations as it is\n";
				cin>>source>>destination>;
				if(g.hasPath(source,destination))
					cout<<"path exist \t\t\t\n";
				else
					cout<<"sorry! No path exist\n";
				break;
				
			case 4 : string source,destination;
				g.display_stations();
				cout<<"please enter stations name from given stations as it is\n";
				cin>>source>>destination>;
				int dist=get_minimum_dist(source,destination);
				if(dist==1e9)cout<<"No path between two stations\n. please enter correct station\n";
				else cout<<"minimum distance is :\t "<<dist<<endl;
				break;
				
			default :cout<<"invalid choice \n.please provide valid input \n";
				 break;
		}
		
	}
	
}
