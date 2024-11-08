#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm> 
using namespace std;

//Summation all point of members from vector member func
auto sumMembers(map <string, vector <int>> membersList, vector<string> surnamesList) {
	map <string, int> membersListWithSum;
	for (int i = 0;i != surnamesList.size();++i) 
	{
		for (int j = 0;j != 3;++j) {
			membersListWithSum[surnamesList[i]] += membersList[surnamesList[i]][j];
		}
	}
	return membersListWithSum;
}

//Printing rangared list func
void printList(vector<string> sortedSurnames, map <string, vector <int>> membersList, map <string, int> membersWithSum) {
	for (int i = 0;i != sortedSurnames.size();++i)
	{
		cout << i + 1 << ". " << sortedSurnames[i] << " ";
		cout << membersList[sortedSurnames[i]][0] << " ";
		cout << membersList[sortedSurnames[i]][1] << " ";
		cout << membersList[sortedSurnames[i]][2] << " ";
		cout << "(" << membersWithSum[sortedSurnames[i]] << ")" << endl;
	}
}

//Ranging func
void ranging(map <string, vector <int>> membersList, vector<string> surnamesList) {
	map <string, int> membersWithSum = sumMembers(membersList, surnamesList); //Get a dictionary type {surname,points}
	vector <string> sortedSurnames;//For sorting surnames by points
	for (int j = 0; j < surnamesList.size();++j) 
	{
		int	min = j;
		for (int k = j+1; k < surnamesList.size();++k)
		{
			if (membersWithSum[surnamesList[k]] < membersWithSum[surnamesList[min]])
			{
				min = k;
			}
		}
		vector<string>::iterator it;
		sortedSurnames.push_back(surnamesList[min]);
		it = find(surnamesList.begin(), surnamesList.end(), surnamesList[min]);
		surnamesList.erase(it);
		j--;
	}
	//Printing sorted list of members
	printList(sortedSurnames, membersList, membersWithSum);
}
