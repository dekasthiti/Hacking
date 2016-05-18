#include <iostream>
#include <vector>
#include <string> // Must include <string> to have cin >> string and cout << string working
using namespace std;


class Person {
protected:
	string firstName;
	string lastName;
	int id;
public:
	Person(string firstName, string lastName, int identification) {
		this->firstName = firstName;
		this->lastName = lastName;
		this->id = identification;
	}
	void printPerson() {
		cout << "Name: " << lastName << ", " << firstName << "\nID: " << id << "\n";
	}

};

class Student : public Person {
private:
	vector<int> testScores;
public:
	// Write your constructor

	/*
	Pay particular attention to this constructor.
	It is parametric, but the base class has to be in the initialization list
	Otherwise it complains: Person() does not have a default constructor
	*/
	Student(string firstName, string lastName, int identification, vector<int> scores):Person(firstName, lastName, identification), testScores(scores)
	{
	}

	// Check this doesn't work either
	//Student(string firstName, string lastName, int identification, vector<int> scores): testScores(scores)
	//{
	//	Person(firstName, lastName, identification);
	//}
	// Write char calculate()
	char calculate()
	{
		size_t scoresCount = testScores.size();
		unsigned int sum = 0;
		char a;
		for (unsigned int i = 0; i < scoresCount; i++)
		{
			sum = sum + testScores[i];
		}

		unsigned int average = sum / scoresCount; //int?

		if (average >= 90 && average <= 100)
			a = 'O';
		else if (average >= 80 && average < 90)
			a = 'E';
		else if (average >= 70 && average < 80)
			a = 'A';
		else if (average >= 55 && average < 70)
			a = 'P';
		else if (average >= 40 && average < 55)
			a = 'D';
		else if (average < 40)
			a = 'T';

		return a;
	}
};

int main_inheritance() {
	string firstName;
	string lastName;
	int id;
	int numScores;
	cin >> firstName >> lastName >> id >> numScores;
	vector<int> scores;
	for (int i = 0; i < numScores; i++) {
		int tmpScore;
		cin >> tmpScore;
		scores.push_back(tmpScore);
	}
	Student* s = new Student(firstName, lastName, id, scores);
	s->printPerson();
	cout << "Grade: " << s->calculate() << "\n";
	return 0;
}