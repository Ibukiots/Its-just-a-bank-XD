#include<vector>
#include<iostream>
using namespace std;

class List {
private:
	vector<int> Node;
public:
	List(){}
	void SetNode(const int& val) {
		Node.push_back(val);
	};
	void PrintNode() {
		for (int val : Node) {
			cout << val << endl;
		}
	}
	void ModifyNode(int index, const int& val) {
		if (index<0 || index>Node.size()) {
			throw out_of_range("Index out of range!");
		}
		else {
			Node[index] = val;
		}
	}
};

int main() {
	List DemoList;
	DemoList.SetNode(1);
	DemoList.SetNode(1);
	DemoList.SetNode(4);
	DemoList.SetNode(5);
	DemoList.SetNode(1);
	DemoList.SetNode(3);
	DemoList.ModifyNode(5, 4);
	DemoList.PrintNode();
	return 0;
}
