#include <iostream> 
#include <list>
#include <cmath> 
using namespace std;

int main (int argc, char *argv[]) {
	list<long> differences;
	long x, y;
	while (scanf("%ld %ld", &x, &y) != EOF)
		differences.push_back(abs(x-y));

	list<long>::iterator i;
	for( i = differences.begin(); i != differences.end(); ++i)
		cout << *i << endl;
}