// Graphs.cpp : Defines the entry point for the console application.
// Author: Sthiti Deka
// Created: 22nd July 2016

#include <string> // for: string
#include <list>   // for: list
#include <set>    // for: set
#include <queue>  // for: queue
#include <map>
#include <stack>
#include <iostream>

using namespace std;

// forward declaring classes to work around compiler dependency errors (a needs b, b needs a, pre-declare both)
class Vertex;
class Edge;
class Graph;
enum Status
{
	Unvisited = 0, 
	InProgress = 1, 
	Visited = 2 
};

// Edge is referenced in Vertex while creating the adjacency list,
// and has to be defined before using it in Vertex to avoid C2027: use of undefined type 'Edge'
// Note that there is use of vertex* as a parameter and return type, and for that, definition is not required, just declaration 
// will suffice
class Edge
{
public:
	Edge(Vertex* v, int w) :to(v), weight(w)
	{
	}
	int getWeight()
	{
		return weight;
	}
	Vertex* getToNode()
	{
		return to;
	}

private:
	Vertex* to;
	int weight;
};

class Vertex 
{
public: 
	Vertex(string a): data(a)
	{
		visitStatus = Status::Unvisited;
	}

	void add(Edge *e)
	{
		edges.push_back(e);
	}

	list<Edge*> getEdges()
	{
		return edges;
	}
	string getData()
	{
		// Don't change the status implicitly
		//visitStatus = Status::Visited;
		return data;
	}
	unsigned getVisitStatus()
	{
		return visitStatus;
	}

	void setVisitStatus(Status s)
	{
		if (s >= Status::Unvisited && s <= Status::Visited)
		{
			visitStatus = s;
		}
	}
	list<Vertex*> getAdjList()
	{
		for (list<Edge*>::iterator lItr = edges.begin(); lItr != edges.end(); lItr++)
		{
			Edge* e = static_cast<Edge*>(*lItr);
			Vertex* v = e->getToNode();
			adjList.push_back(v);
		}
		return adjList;
	}


private:
	string data;
	list<Edge*> edges;
	Status visitStatus;
	list<Vertex*> adjList;

};



class Graph 
{ 
public:
	void add(Vertex* v)
	{
		vertices.insert(v);
	}

	set<Vertex*> getVertices()
	{
		return vertices;
	}

	void DFS(Vertex* start, Vertex* goal)
	{
		// If both start and goal are valid
		if (start && goal)
		{
			Vertex* v = start;
			if (v->getData() == goal->getData())
			{
				cout << goal->getData();
				return;
			}
			else if (v->getVisitStatus() == Status::Unvisited)
			{
				v->setVisitStatus(Status::InProgress);

				// Now visit all the neighbors
				list<Edge*> vEdges = v->getEdges();
				for (list<Edge*>::iterator lItr = vEdges.begin(); lItr != vEdges.end(); lItr++)
				{
					// print v
					Edge* e = *lItr;
					Vertex* neighbor = e->getToNode();
					if (neighbor->getVisitStatus() == Status::Unvisited)
					{
						cout << v->getData() << "---->";
						DFS(neighbor, goal);
					}
				}
				v->setVisitStatus(Status::Visited);
			}
			else // Node was visited, return to the caller in the recursion stack
			{
				return;
			}
		}
		else
		{
			return;
		}
	}

	void BFT(Vertex* start)
	{
		queue<Vertex*> BFTQueue;

		// Traverse if the start node is valid and has not been visited yet
		if (start && start->getVisitStatus() == Status::Unvisited)
		{
			// 1. Insert node in a queue
			BFTQueue.push(start);

			// 2. Dequeue. Process node. Insert unvisited nodes in its adjacency list
			while (!BFTQueue.empty())
			{
				Vertex* v = BFTQueue.front();
				list<Edge*> edges = v->getEdges();
				for (list<Edge*>::iterator lItr = edges.begin(); lItr != edges.end(); lItr++)
				{
					v->setVisitStatus(Status::Visited);
					//Process v
					cout << " " << v->getData();
					Edge* e = *lItr;
					Vertex* neighbor = e->getToNode();
					if (neighbor->getVisitStatus() != Status::Visited)
					{
						BFTQueue.push(neighbor);
					}
				}
				BFTQueue.pop();
			}
			// 3. Repeat till there are no nodes in the queue.
			
		}
		else
		{
			// Nothing to traverse
			return;
		}
	}

	void DFT(Vertex* u)
	{
		if (u)
		{
			cout << u->getData() << "-------->";
			u->setVisitStatus(Status::Visited);   // Mark when you first see, before calling DFT on its adjacent vertices
			list<Vertex*> adjList = u->getAdjList();
			for (list<Vertex*>::iterator lItr = adjList.begin(); lItr != adjList.end(); lItr++)
			{
				Vertex* v = *lItr;

				if (v->getVisitStatus() != Status::Visited)
				{
					pathTo[v] = u;
					DFT(v);
				}
			}
		}
		else
		{
			return;
		}
	}

	void DFT_iterative(Vertex* u)
	{
		stack<Vertex*> S;
		if (u)
		{
			u->setVisitStatus(Status::Visited); // Mark before pushing to stack
			S.push(u);

			while (!S.empty())
			{
				u = static_cast<Vertex*>(S.top());
				S.pop();
				cout << u->getData() << "-------->";
				//u->setVisitStatus(Status::Visited);  // Marking after popping from stack makes us revisit the same vertex many more times while iterating through adj list

				list<Vertex*> adjList = u->getAdjList();

				for (list<Vertex*>::iterator lItr = adjList.begin(); lItr != adjList.end(); lItr++)
				{
					Vertex* v = *lItr;
					if (v->getVisitStatus() != Status::Visited)
					{
						pathTo[v] = u;
						v->setVisitStatus(Status::Visited); // Mark before pushing to stack
						S.push(v);
					}
				}

			}

		}
	}
private:
    set<Vertex*> vertices; 
	map<Vertex*, Vertex*> pathTo;
	map<Vertex*, vector<Vertex*>> adjList;
};


int main()
{
	Graph *g = new Graph();

	// hash_set is deprecated. Use unordered set
	// this could be g->vertices = new unordered_set<Vertex>();
	 //g->vertices = new hash_set<Vertex>(); 

	Vertex *s = new Vertex("s");
	Vertex *a = new Vertex("a");
	Vertex *b = new Vertex("b");
	Vertex *c = new Vertex("c");
	Vertex *d = new Vertex("d");

	g->add(s);
	g->add(a);
	g->add(b);
	g->add(c);
	g->add(d);
	
	s->add(new Edge(a, 8));
	a->add(new Edge(b, 10));
	b->add(new Edge(c, 5));
	d->add(new Edge(c, 2));
	s->add(new Edge(b, 7));
	c->add(new Edge(d, 3));


	// Print the graph
	set<Vertex*> graphVertices = g->getVertices();
	for (set<Vertex*>::iterator vItr = graphVertices.begin(); vItr != graphVertices.end(); vItr++)
	{
		Vertex* v = *vItr;
		list<Edge*> vEdges = v->getEdges();

		//if (v->getVisitStatus() != Status::Visited)
		{

			for (list<Edge*>::iterator lItr = vEdges.begin(); lItr != vEdges.end(); lItr++)
			{
				cout << v->getData();
				Edge* e = *lItr;
				cout.width(3);
				cout << "----" << e->getWeight() << "---->" << e->getToNode()->getData() << endl;
			}
			cout << endl;
		}		
	}
	
	cout << "=========DFS=========" << endl;
	cout << "\nSearching from s to c" << endl;
	g->DFS(s, c);

	cout << "\nSearching from c to d" << endl;
	g->DFS(c, d);

	// Modify this to traverse the graph without a start node
	// Reset the visit status of all the nodes. This should change. Client shouldnt' have to do this?
	s->setVisitStatus(Status::Unvisited);
	a->setVisitStatus(Status::Unvisited);
	b->setVisitStatus(Status::Unvisited);
	c->setVisitStatus(Status::Unvisited);
	d->setVisitStatus(Status::Unvisited);

	cout << "\n\n=========BFT=========" << endl;
	g->BFT(s);

	// Modify this to traverse the graph without a start node
	// Reset the visit status of all the nodes. This should change. Client shouldnt' have to do this?
	s->setVisitStatus(Status::Unvisited);
	a->setVisitStatus(Status::Unvisited);
	b->setVisitStatus(Status::Unvisited);
	c->setVisitStatus(Status::Unvisited);
	d->setVisitStatus(Status::Unvisited);

	cout << "\n\n=========DFT=========" << endl;
	g->DFT(s);

	// Modify this to traverse the graph without a start node
	// Reset the visit status of all the nodes. This should change. Client shouldnt' have to do this?
	s->setVisitStatus(Status::Unvisited);
	a->setVisitStatus(Status::Unvisited);
	b->setVisitStatus(Status::Unvisited);
	c->setVisitStatus(Status::Unvisited);
	d->setVisitStatus(Status::Unvisited);

	cout << "\n\n==========DFT Iterative========" << endl;
	g->DFT_iterative(s);


    return 0;
}

