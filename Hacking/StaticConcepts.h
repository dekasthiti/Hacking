int main_StaticConcepts();
int main_StaticConcepts2();

struct counter
{
	int a;
	char b;
	float c;
};
// This becomes a global declaration. 

static struct counter
{
	int a;
	char b;
	float c;
}myStaticCounter;
// If struct is qualified with static, an instance has to be declared as well, otherwise you get the warning C4091: 'static' ignored
// on left of counter when no variable is declared.
// However, if it is declared and instantiated as static here, each file that includes it will get its own copy and changes in one file
// will not be visible in another file.
