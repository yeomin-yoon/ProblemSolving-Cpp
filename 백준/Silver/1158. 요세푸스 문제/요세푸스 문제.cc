#include <iostream>
#include <list>
using namespace std;

int main()
{
	list<int> NumList;
	int NumLength, Interval;

	cin >> NumLength >> Interval;

	// 1. 리스트 초기화
	for (int Num = 1; Num <= NumLength; Num++)
	{
		NumList.push_back(Num);
	}

	// 2. 현재 노드 초기화
	auto Node = NumList.begin();


	cout << "<";

	// 3. 리스트가 빌 때까지 반복
	while (!NumList.empty())
	{
		// (1) K-1번 이동
		for (int Index = 0; Index < Interval - 1; Index++)
		{
			Node++;

			if (Node == NumList.end())	// 끝이면 다시 처음으로
			{
				Node = NumList.begin();
			}
		}

		// (2) 현재 노드 출력
		cout << *Node;

		// (3) 현재 노드 삭제 + 다음 노드로 이동
		Node = NumList.erase(Node);

		if (Node == NumList.end())	// 끝이면 다시 처음으로
		{ 
			Node = NumList.begin();
		}


		if (!NumList.empty())
			cout << ", ";
	}

	cout << ">";
}