/*
A palindrome is a word, phrase, number, or other sequence of characters which reads the same backwards and forwards.Can you determine if a given string, , is a palindrome ?

To solve this challenge, we must first take each character in, enqueue it in a queue, and also push that same character onto a stack.Once that's done, we must dequeue the first character from the queue and pop the top character off the stack, then compare the two characters to see if they are the same; as long as the characters match, we continue dequeueing, popping, and comparing each character until our containers are empty (a non-match means  isn't a palindrome).

 */
#include <iostream>
#include <stack>  // for stack
#include <queue>  // for queue
#include <string> // for getline

using namespace std;

class Solution {
	//Write your code here
public:
	void pushCharacter(char a) {
		m_Stack.push(a);
	}

	char popCharacter() {
		char tmp = m_Stack.top();
		m_Stack.pop();
		return tmp;
	}

	void enqueueCharacter(char a) {
		m_Queue.push(a);
	}

	char dequeueCharacter() {
		char tmp = m_Queue.front();
		m_Queue.pop();
		return tmp;
	}

private:
	stack<char> m_Stack;
	queue<char> m_Queue;
};

int main_palindrome() {
	// read the string s.
	string s;
	getline(cin, s);

	// create the Solution class object p.
	Solution obj;

	// push/enqueue all the characters of string s to stack.
	for (size_t i = 0; i < s.length(); i++) {
		obj.pushCharacter(s[i]);
		obj.enqueueCharacter(s[i]);
	}

	bool isPalindrome = true;

	// pop the top character from stack.
	// dequeue the first character from queue.
	// compare both the characters.
	for (size_t i = 0; i < s.length() / 2; i++) {
		if (obj.popCharacter() != obj.dequeueCharacter()) {
			isPalindrome = false;

			break;
		}
	}

	// finally print whether string s is palindrome or not.
	if (isPalindrome) {
		cout << "The word, " << s.c_str() << ", is a palindrome.";
	}
	else {
		cout << "The word, " << s.c_str() << ", is not a palindrome.";
	}

	return 0;
}