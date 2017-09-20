#include "Strings.h"
#include <iostream>
#include <map>
#include <unordered_map> // For hash tables
#include <unordered_set> // For hash sets. Value is the key
#include <string>
#include <bitset>
#include <string>

using namespace std;

bool isUnique(char* input)
{
	int bitArray = 0;
	map<char, int> alphabetMap;
	bool isUniqueString = true;
	if (input == NULL)
	{
		return false; // false?
	}
	else
	{
		unsigned int length = strlen((const char*)input);
		for (unsigned int i = 0; i < length; i++)
		{
			char a = input[i];
			if (alphabetMap.find(a) != alphabetMap.end())
			{
				// The letter is already there
				cout << "\n" << a << " exists, quitting \n";
				isUniqueString = false;
				break;
			}
			else
			{
				pair<char, int> entry = make_pair(a, 1);
				// enter into the map
				alphabetMap.insert(entry);
			}
		}

	}

	if (isUniqueString == false)
	{
		cout << "\n" << input << " is not a unique string " << endl;
	}
	else
	{
		cout << "\n" << input << " is a unique string!! " << endl;

	}
	return isUniqueString;
}

// Implementation 1: Using maps
bool isPermutationMap(char* set, char *test)
{
	// Check the length of both strings, if not equal, quit
	size_t setLen = strlen(set);
	size_t testLen = strlen(test);
	bool permCheckResult = true;

	if (setLen != testLen)
	{
		return false;
	}

	// Otherwise, populate a map with the set string. Increment count if there are duplicate letters
	map<char, int> alphabetMap;
	for (unsigned int i = 0; i < setLen; i++)
	{
		char a = set[i];

		if (alphabetMap.find(a) != alphabetMap.end())
		{
			unsigned int count = alphabetMap[a];
			alphabetMap[a] = ++count;
		}
		else
		{
			pair<char, unsigned int> entry = make_pair(a, 1);
			alphabetMap.insert(entry);
		}		
	}


	// Then, check if letters in test are found in the map. If they are, decrement count. Count should be 0 at the end of testing the test string.

	for (unsigned int i = 0; i < testLen; i++)
	{
		char t = test[i];

	    map<char, int>::iterator itr = alphabetMap.find(t);
		if (itr != alphabetMap.end())
		{
			int count = itr->second;
			alphabetMap[t] = --count;
		}
		else
		{
			// not found
			permCheckResult = false;
			cout << "\n" << test << " is not a permutation of " << set << ", quitting " << endl;
			break;
		}
	}

	if (permCheckResult != false)
	{
		for (map<char, int>::iterator itr = alphabetMap.begin(); itr != alphabetMap.end(); itr++)
		{
			// Since we decrement, if there are equal number of characters in the test string, we should have parity
			// If it is greater or lesser than 0, then the test is not a permutation
			if (itr->second > 0 || itr->second < 0)  // if (itr->second != 0)
			{
				permCheckResult = false;
				break;
			}
		}
	}

	if (permCheckResult == false)
	{
		cout << "\n" << test << " is not a permutation of " << set << ", quitting " << endl;
	}
	else
	{
		cout << "\n" << test << " is  a permutation of " << set << "!! " << endl;

	}

	return permCheckResult;

}

// Implementation 2: Using bitset: When the length is known
bool isPermutationBitSet(char* input, char* test)
{
	bitset<128> alphabetInputFlag; // if left uninitialized, 128 bits will be set to zero.
	bitset<128> alphabetTestFlag; // if left uninitialized, 128 bits will be set to zero.

	bool result = true;

	unsigned int inputLen = strlen(input);
	unsigned int testLen = strlen(test);

	if (inputLen == testLen)
	{
		for (unsigned int i = 0; i < inputLen; i++)
		{
			unsigned int inputFlagIndex = input[i] - '\0'; // is NULL the first character?
			alphabetInputFlag.set(inputFlagIndex);

			unsigned int testFlagIndex = test[i] - '\0';
			alphabetTestFlag.set(testFlagIndex);
		}

		cout << "\nInput Bit Flag: " << alphabetInputFlag.to_string() << endl;
		cout << "\nTest Bit Flag: " << alphabetTestFlag.to_string() << endl;

		if (alphabetInputFlag != alphabetTestFlag)
		{
			result = false;
			cout << "\n" << test << " is not a permutation of " << input << endl;
		}
		else
		{
			cout << "\n" << test << " is a permutation of " << input << "!!" << endl;
		}
	}
	else
	{
		cout << "\n" << test << " is not a permutation of " << input << endl;
	}
	return result;
}


// Implementation 3: Using vector<bool>: When the length is dynamic
bool isPermutationBoolVector(char* input, char* test)
{
	vector<bool> alphabetInputFlag;
	vector<bool> alphabetTestFlag;


	bool result = true;
	cout << "This is not implemented correctly!!";
	//unsigned int inputLen = strlen(input);
	//unsigned int testLen = strlen(test);

	//alphabetInputFlag.reserve(inputLen);
	//alphabetTestFlag.reserve(testLen);

	//if (inputLen == testLen)
	//{
	//	for (unsigned int i = 0; i < inputLen; i++)
	//	{
	//		unsigned int inputFlagIndex = input[i] - '\0'; // is NULL the first character?
	//		alphabetInputFlag[inputFlagIndex] = 1;

	//		unsigned int testFlagIndex = test[i] - '\0';
	//		alphabetTestFlag[testFlagIndex] = 1;
	//	}

	//	if (alphabetInputFlag != alphabetTestFlag)
	//	{
	//		result = false;
	//		cout << "\n" << test << " is not a permutation of " << input << endl;
	//	}
	//	else
	//	{
	//		cout << "\n" << test << " is a permutation of " << input << "!!" << endl;
	//	}
	//}
	//else
	//{
	//	cout << "\n" << test << " is not a permutation of " << input << endl;
	//}
	

	return result;
}

// Implementation 4: Using hash tables
bool isPermutationHashTable(char* input, char* test)
{
	bool result = true;
	unordered_map<string, int> alphabetMap;
	
	unordered_map<string, int>::hasher hashFn = alphabetMap.hash_function();

	size_t inputHash = hashFn(input);
	size_t testHash = hashFn(test);

	cout << "\nHash of " << input << " is: " << inputHash << endl;
	cout << "\nHash of " << test << " is: " << testHash << endl;

	if (inputHash != testHash)
	{
		cout << "\n" << test << " is not a permutation of " << input << endl;
	}
	else
	{
		cout << "\n" << test << " is a permutation of " << input << "!!" << endl;
	}

	return result;
}

// Implementation 5: Using hash sets. This makes more sense for this example since we don't care about a value.
bool isPermutationHashSet(char* input, char* test)
{
	bool result = true;
	unordered_set<string> alphabetSet;

	unordered_set<string>::hasher hashFn = alphabetSet.hash_function();

	size_t inputHash = hashFn(input);
	size_t testHash = hashFn(test);

	cout << "\nHash of " << input << " is: " << inputHash << endl;
	cout << "\nHash of " << test << " is: " << testHash << endl;

	if (inputHash != testHash)
	{
		cout << "\n" << test << " is not a permutation of " << input << endl;
	}
	else
	{
		cout << "\n" << test << " is a permutation of " << input << "!!" << endl;
	}

	return result;
}

// Calculate the maximum frequency of a substring in a string
// eg. abcde: 1
// eg. ababcd : 2
// eg. abcbcd : 2
unsigned int subStringFrequency()
{
	unsigned int N;
	unsigned short K, L, M;

	unsigned int maxSubtringFreq = 1;

	//map<char*, unsigned int> stringCountMap;
	map<string, unsigned int> stringCountMap;


	// Read in N, size of the input string. This will be 1 less than strlen. N >= 2 AND N <=100000
	cout << "\nEnter length of string:";
	cin >> N;

	// Read in K, L, M in space separated input. 
	cout << "\nEnter K, L, M in space separated line:";
	cin >> K >> L >> M; 
	// TO DO: Check if this should be received taking delimiter into account;

	char* inputString = (char*)malloc(N * sizeof(char) + 1);


	if (N >= 2 && N <= 10000) //constraint on N
	{
		// proceed
		if (K >= 2 && K <= 26 && L >= 2 && L <= 26 && L < N) // constraints on K, L
		{
			// proceed
			if (M >= 2 && M <= 26)
			{
				// proceed
				if (inputString != NULL) // was malloc successful?
				{
					cin >> inputString;


					//if (strlen(inputString) == N) // check if input string length exceeds what's provided
					{
							// Test only
							//cout << "\n" << inputString << endl;

							
							// Enter all substrings from length K to L in map
							for (unsigned int i = K; i <= L; i++)
							{
								// Initialize the start of the string;
								char* strPointer = inputString;

								// Enter all substrings of length i to map
								while (*strPointer != '\0')
								{
									char* tmpSubString = (char*)malloc(i * sizeof(char) + 1);
									if (tmpSubString != NULL)
									{
										for (unsigned int j = 0; j < i; j++)
										{
											tmpSubString[j] = strPointer[j];
										}
										tmpSubString[i] = '\0';

										// To Do: Check if DISTINCT characters <=M

										// Can you find this in the map?
										// (don't enter if for some reason we got the wrong substrings)
										if (strlen(tmpSubString) == i)
											// To do: check for unique characters not exceeding M  as well
											// Unique characters = Total length - number of repetitions
										{
											// Why does this fail when stringCountMap is <char*, int>??

											//if (stringCountMap.find((tmpSubString)) != stringCountMap.end())

											if (stringCountMap.find(string(tmpSubString)) != stringCountMap.end())
											{
												unsigned int tmpCount = stringCountMap[tmpSubString];
												stringCountMap[tmpSubString] = ++tmpCount; // pre-increment only can update
											}
											else
											{
												//stringCountMap.insert(pair<char*, unsigned>(tmpSubString, 1));
												stringCountMap.insert(make_pair(string(tmpSubString), 1));
											}
										}
										strPointer++;
										free(tmpSubString);
									}
									
								}



							// Now find the most frequently occuring substring
							//for (map<char*, unsigned int>::iterator itr = stringCountMap.begin(); itr != stringCountMap.end(); itr++)
							for (map<string, unsigned int>::iterator itr = stringCountMap.begin(); itr != stringCountMap.end(); itr++)

							{
								unsigned int tmpCount = itr->second;
								maxSubtringFreq = (tmpCount > maxSubtringFreq) ? tmpCount : maxSubtringFreq;
							}
						}
					}
				}

				else
				{
					cout << "\nMalloc failed. Quitting" << endl;
					return 0;
				}

			}
			else
			{
				cout << "\nConstraint on M failed. Quitting" << endl;
				return 0;
			}
		}
		else
		{
			cout << "\nConstraint on K, L failed. Quitting" << endl;
			return 0;
		}

	}
	else
	{
		cout << "\nConstraint on N failed. Quitting" << endl;
		return 0;
	}
	free(inputString);
	return maxSubtringFreq;
}

// Check if a string is a rotation of another string
bool isRotatedString(string input, string test)
{
	bool isRotated = false;

	// Early return: if strings are not of the same length.
	size_t inputStrLen = strlen(input.data());
	size_t testStrLen = strlen(test.data());

	if (inputStrLen == testStrLen)
	{
		// ttlebo is a rotation of bottle
		// and ttlebo is a substring of bottlebottle
		string tmp = input + input; 
		string checkSubStr;
		size_t tmpStrLen = 2 * inputStrLen;
		for (size_t i = 0; i < tmpStrLen; i++)
		{
			checkSubStr = tmp.substr(i, testStrLen);
			if (checkSubStr == test)
			{
				isRotated = true;
			}
		}
	}
	
	return isRotated;
}
// Time: O(2N)
// Space: O(N^2) : checkSubStr for every i in tmp

void reverse(char* inputStr, char** revStr)
{
	// The following code will never work as long as we allocating memory on the heap inside the callee, because the pointers are invalid when 
	// the call returns

	// Implementation 1: Iterate from the end of the input string to the beginning
	// Time: O(n)
	// Space: O(2n)
	int len = strlen(inputStr);
	/*revStr = (char*)malloc(len + 1);*/ // Allocating memory in the callee will not work. Adding a reference to this pointer should work?

	if (revStr)
	{
		for (int i = len; i > 0; i--)
		{
			*(*revStr + ( i - 1)) = inputStr[len - i];
		}
		(*revStr)[len] = '\0';
	}

	// Implementation 1: In place?
}

int reverseEntireString(string& test, int startpos, int endpos)
{
	char tmp;
	while (startpos < endpos)
	{
		tmp = test[endpos-1];
		test[endpos-1] = test[startpos];
		test[startpos] = tmp;
		startpos++;
		endpos--;
	}
	return 0;
}
// Input: "I am a test stringo!"
// Output: "stringo! test a am I"
int reverseString( string& input)
{
	if (!input.empty())
	{
		// 1. Reverse the string, character by character
		reverseEntireString(input, 0, input.length());

		// 2. Reverse each word
		int stringStart = 0;
		int stringEnd = input.length();
		int wordStart = 0;
		int wordlen = 0;
		int wordEnd = 0;

		char tmp;
		while (stringStart < stringEnd)
		{
			wordlen = 0; //for every new word
			wordStart = stringStart;

			while ((wordStart + wordlen < stringEnd ) && input[wordStart + wordlen] != ' ')
			{
				wordlen++;
			}
			wordEnd = wordStart + wordlen;

			while (wordStart < wordEnd)
			{
				// swap letters of the word
				tmp = input[wordEnd -1] ;
				input[wordEnd - 1] = input[wordStart];
				input[wordStart] = tmp;
				wordStart++;
				wordEnd--;
			}
			stringStart += wordlen ;
			stringStart++; //skipping the space
		}

	}
	return 0;

}

int main_Strings()
{
	char* input = "hello";
	char* output = (char*)malloc(strlen(input) + 1);
	reverse(input, &output);
	printf("Reverse of %s is %s", input, output);

	if (output)
		free(output);


	std::string str = "I am a test stringo!";
	reverseString(str);
	cout << "Reversed string is " << str;
	return 0;
}