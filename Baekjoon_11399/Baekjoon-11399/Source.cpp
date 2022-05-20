#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
using namespace std;


int Person[1001];

int main() {

	int N;
	int sum = 0;
	int result = 0;

	cin >> N;

	for (int i = 1; i <= N; i++) {
		int person;

		cin >> person;
		Person[i] = person;
	}

	for (int i = 1; i <= N; i++) {
		sort(Person, Person + N + 1);
	}

	for (int i = 1; i <= N; i++) {
		sum += Person[i];
		result += sum;
	}

	cout << result << endl; 

	return 0;
}