// Graphs.cpp : Defines the entry point for the console application.
// Author: Sthiti Deka
// Created: 22nd July 2016

#include <string> // for: string
#include <list>   // for: list
#include <set>    // for: set
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
		visitStatus = Status::Visited;
		return data;
	}
	unsigned getVisitStatus()
	{
		return visitStatus;
	}

private:
	string data;
	list<Edge*> edges;
	Status visitStatus;
};

class Edge 
{
public: 
	Edge(Vertex* v, int w):to(v), weight(w)
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
private:
    set<Vertex*> vertices; 
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
	

    return 0;
}

