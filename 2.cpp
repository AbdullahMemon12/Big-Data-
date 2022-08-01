#include<iostream>
#include<conio.h>
#include<string>
#include<fstream>
#include <sstream>

using namespace std;

class Node3{
	public:
		string airline;
		float average;
		int height;
		Node3* left,*right;
		Node3()
		{
			height = 0;
			left = NULL;
			right = NULL;
		}
		Node3(string a, float avg)
		{
			airline = a;
			average = avg;
			height = 0;
			left = NULL;
			right = NULL;
		}
};

class AVL3{
		Node3* root;
	public:
		AVL3()
		{
			root = NULL;
		}
		int heightret(Node3* N)
		{
			if (N == NULL)
			{
				return -1;
			}
			return N->height;
		}
		Node3* rightRotate(Node3* y)
		{
			Node3* x = y->left;
			if(y->left==NULL)
			{
				return y;
			}
			if (y->left->right == NULL)
			{
				x->right = y;
				y->left = NULL;
				return x;
			}
			Node3* T2 = x->right;
			x->right = y;
			y->left = T2;
			y->height = max(heightret(y->left), heightret(y->right)) + 1;
			x->height = max(heightret(x->left), heightret(x->right)) + 1;
	
			return x;
		}
		Node3* leftRotate(Node3* y)
		{
			Node3* x = y->right;
			if(y->right==NULL)
			{
				return y;
			}
			if (y->right->left == NULL)
			{
				x->left = y;
				y->right = NULL;
				return x;
			}
			Node3* T2 = x->left;
			x->left = y;
			y->right = T2;
			y->height = max(heightret(y->left), heightret(y->right)) + 1;
			x->height = max(heightret(x->left), heightret(x->right)) + 1;
	
			return x;
		}
		int getBalanceFactor(Node3* N)
		{
			if (N == NULL)
			{
				return 0;
			}
			return heightret(N->left) - heightret(N->right);
		}
		void insert(Node3* newNode)
		{
			root = insertNode(root, newNode);
		}
		Node3* insertNode(Node3* curr, Node3* newNode)
		{
			if (curr == NULL)
			{
				return newNode;
			}
			else if (newNode->average < curr->average)
			{
				curr->left = insertNode(curr->left, newNode);
			}
			else if (newNode->average >= curr->average)
			{
				curr->right = insertNode(curr->right, newNode);
			}
			else
			{
				return curr;
			}
			curr->height = 1 + max(heightret(curr->left), heightret(curr->right));
			int balanceFactor = getBalanceFactor(curr);
	        if (balanceFactor > 1) 
	        {
	        	if(curr->left)
	        	{
	            	if (newNode->average < curr->left->average)
	                {
	                   return rightRotate(curr);
	                } 
	                else if (newNode->average > curr->left->average) 
	                {
	                    curr->left = leftRotate(curr->left);
	                    return rightRotate(curr);
	                }
				}
	        }
	        if (balanceFactor < -1) 
	        {
	        	if(curr->right)
	        	{
	        		if (newNode->average > curr->right->average) 
	                {
	                   return leftRotate(curr);
	                } 
	                else if (newNode->average < curr->right->average)
	                {
	                    curr->right = rightRotate(curr->right);
	                    return leftRotate(curr);
	                }
				}
	        }
			return curr;
		}
		
		void inOrder(Node3* curr)
		{
			if(curr)
			{
				inOrder(curr->left);
				cout<<curr->airline<<"\t\t\t"<<curr->average<<endl;
				inOrder(curr->right);
			}
		}
		void print()
		{
			cout<<"Airline\t\t\tAverage"<<endl<<endl;
			inOrder(root);
		}
};

class Node2{
	public:
		string airline;
		float avg,sum,num;
		int height;
		bool visited;
		Node2* left, *right;
		Node2()
		{
			avg=0;
			num=0;
			sum=0;
			height = 0;
			visited=0;
			left = NULL;
			right = NULL;
		}
		Node2(string a, int delay)
		{
			airline = a;
			sum = delay;
			avg = delay;
			num = 1;
			left = NULL;
			right = NULL;
		}
};

class AVL2 {
	Node2* root;
public:
	AVL2()
	{
		root = NULL;
	}
	int heightret(Node2* N)
	{
		if (N == NULL)
		{
			return -1;
		}
		return N->height;
	}
	Node2* rightRotate(Node2* y)
	{
		Node2* x = y->left;
		if(y->left==NULL)
		{
			return y;
		}
		if (y->left->right == NULL)
		{
			x->right = y;
			y->left = NULL;
			return x;
		}
		Node2* T2 = x->right;
		x->right = y;
		y->left = T2;
		y->height = max(heightret(y->left), heightret(y->right)) + 1;
		x->height = max(heightret(x->left), heightret(x->right)) + 1;

		return x;
	}
	Node2* leftRotate(Node2* y)
	{
		Node2* x = y->right;
		if(y->right==NULL)
		{
			return y;
		}
		if (y->right->left == NULL)
		{
			x->left = y;
			y->right = NULL;
			return x;
		}
		Node2* T2 = x->left;
		x->left = y;
		y->right = T2;
		y->height = max(heightret(y->left), heightret(y->right)) + 1;
		x->height = max(heightret(x->left), heightret(x->right)) + 1;

		return x;
	}
	int getBalanceFactor(Node2* N)
	{
		if (N == NULL)
		{
			return 0;
		}
		return heightret(N->left) - heightret(N->right);
	}
	void insert(Node2* newNode)
	{
		root = insertNode(root, newNode);
	}
	Node2* insertNode(Node2* curr, Node2* newNode)
	{
		if (curr == NULL)
		{
			return newNode;
		}
		else if (newNode->airline < curr->airline)
		{
			curr->left = insertNode(curr->left, newNode);
		}
		else if (newNode->airline > curr->airline)
		{
			curr->right = insertNode(curr->right, newNode);
		}
		else
		{
			curr->num++;
			curr->sum += newNode->sum;
			curr->avg = curr->sum/curr->num;
			return curr;
		}
		curr->height = 1 + max(heightret(curr->left), heightret(curr->right));
		int balanceFactor = getBalanceFactor(curr);
        if (balanceFactor > 1) 
        {
        	if(curr->left)
        	{
            	if (newNode->airline < curr->left->airline)
                {
                   return rightRotate(curr);
                } 
                else if (newNode->airline > curr->left->airline) 
                {
                    curr->left = leftRotate(curr->left);
                    return rightRotate(curr);
                }
			}
        }
        if (balanceFactor < -1) 
        {
        	if(curr->right)
        	{
        		if (newNode->airline > curr->right->airline) 
                {
                   return leftRotate(curr);
                } 
                else if (newNode->airline < curr->right->airline)
                {
                    curr->right = rightRotate(curr->right);
                    return leftRotate(curr);
                }
			}
        }
		return curr;
	}
	
	void inOrder(Node2* curr, AVL3 *tree)
	{
		if(curr)
		{
			inOrder(curr->left,tree);
			Node3 *newNode;
			newNode = new Node3(curr->airline,curr->avg);
			tree->insert(newNode);
			inOrder(curr->right,tree);
		}
		
	}
	AVL3 createTree()
	{
		AVL3 tree;
		inOrder(root,&tree);
		return tree;
	}
};

class Node {
	public:
		string FlightDate, Reporting_Airline, OriginCityName, DestCityName;
		int DepDelay, ArrDelay;
		int height;
		Node* left, * right;
		Node()
		{
			left = NULL;
			right = NULL;
		}
		Node(string date, string airline, string orgcty, string dstcty, int depDel, int arrDel)
		{
			FlightDate = date;
			Reporting_Airline = airline;
			OriginCityName = orgcty;
			DestCityName = dstcty;
			DepDelay = depDel;
			ArrDelay = arrDel;
			
			left = NULL;
			right = NULL;
		}
};

class AVL {
		Node* root;
	public:
		AVL()
		{
			root = NULL;
		}
		int heightret(Node* N)
		{
			if (N == NULL)
			{
				return -1;
			}
			return N->height;
		}
		Node* rightRotate(Node* y)
		{
			Node* x = y->left;
			if(y->left==NULL)
			{
				return y;
			}
			if (y->left->right == NULL)
			{
				x->right = y;
				y->left = NULL;
				return x;
			}
			Node* T2 = x->right;
			x->right = y;
			y->left = T2;
			y->height = max(heightret(y->left), heightret(y->right)) + 1;
			x->height = max(heightret(x->left), heightret(x->right)) + 1;
	
			return x;
		}
		Node* leftRotate(Node* y)
		{
			Node* x = y->right;
			if(y->right==NULL)
			{
				return y;
			}
			if (y->right->left == NULL)
			{
				x->left = y;
				y->right = NULL;
				return x;
			}
			Node* T2 = x->left;
			x->left = y;
			y->right = T2;
			y->height = max(heightret(y->left), heightret(y->right)) + 1;
			x->height = max(heightret(x->left), heightret(x->right)) + 1;
	
			return x;
		}
		int getBalanceFactor(Node* N)
		{
			if (N == NULL)
			{
				return 0;
			}
			return heightret(N->left) - heightret(N->right);
		}
		void insert(Node* newNode)
		{
			root = insertNode(root, newNode);
		}
		Node* insertNode(Node* curr, Node* newNode)
		{
			if (curr == NULL)
			{
				return newNode;
			}
			else if (newNode->ArrDelay < curr->ArrDelay)
			{
				curr->left = insertNode(curr->left, newNode);
			}
			else if (newNode->ArrDelay >= curr->ArrDelay)
			{
				curr->right = insertNode(curr->right, newNode);
			}
			else
			{
				return curr;
			}
			curr->height = 1 + max(heightret(curr->left), heightret(curr->right));
			int balanceFactor = getBalanceFactor(curr);
	        if (balanceFactor > 1) 
	        {
	        	if(curr->left)
	        	{
	            	if (newNode->ArrDelay < curr->left->ArrDelay)
	                {
	                   return rightRotate(curr);
	                } 
	                else if (newNode->ArrDelay > curr->left->ArrDelay) 
	                {
	                    curr->left = leftRotate(curr->left);
	                    return rightRotate(curr);
	                }
				}
	        }
	        if (balanceFactor < -1) 
	        {
	        	if(curr->right)
	        	{
	        		if (newNode->ArrDelay > curr->right->ArrDelay) 
	                {
	                   return leftRotate(curr);
	                } 
	                else if (newNode->ArrDelay < curr->right->ArrDelay)
	                {
	                    curr->right = rightRotate(curr->right);
	                    return leftRotate(curr);
	                }
				}
	        }
			return curr;
		}
		
		void sDelay(Node* curr, string org, string dst)
		{
			if (curr)
			{
				sDelay(curr->left,org,dst);
				if(curr->OriginCityName == org && curr->DestCityName == dst)
				{
					cout << curr->FlightDate << "\t\t" << curr->Reporting_Airline << "\t\t" << curr->ArrDelay << "\t\t" << curr->OriginCityName << "\t\t\t" << curr->DestCityName << endl;
				}
				sDelay(curr->right,org,dst);
			}
		}
		void shortestDelay(string org, string dst)
		{
			cout<<endl<<"Flight date\t\tAirline\t\tDelay\t\tOrigin\t\t\t\tDestination"<<endl;
			sDelay(root, org, dst);
		}
		
		void fDate(Node* curr, string date)
		{
			if (curr)
			{
				fDate(curr->left,date);
				if(curr->FlightDate == date)
				{
					cout << curr->FlightDate << "\t\t" << curr->Reporting_Airline << "\t\t" << curr->ArrDelay << "\t\t" << curr->OriginCityName << "\t\t\t" << curr->DestCityName << endl;
				}
				fDate(curr->right,date);
			}
		}
		void flightsOnDate(string date)
		{
			cout<<"Flight date\t\tAirline\t\tDelay\t\tOrigin\t\t\tDestination"<<endl;
			fDate(root, date);
		}
		
		AVL2 airlineTree(Node* curr, AVL2 *tree)
		{
			if (curr)
			{
				airlineTree(curr->left, tree);
				Node2 *newNode;
				newNode = new Node2(curr->Reporting_Airline,curr->ArrDelay);
				tree->insert(newNode);
				airlineTree(curr->right, tree);
			}
		}
		AVL2 createAirlineTree()
		{
			AVL2 tree;
			airlineTree(root,&tree);
			return tree;
		}
};

AVL loadData()
{
	AVL tree;
	ifstream input("Filtered_Data.csv");
	
	string FlightDate, Reporting_Airline, OriginCityName, DestCityName, nop;
	char c;
	int DepDelay, ArrDelay;

	int i, j;
	for(j=0;j<1000;j++)
	{
		DepDelay = INT_MAX;
		ArrDelay = INT_MAX;
		
		fflush(stdin);
		
		getline(input, FlightDate, ',');
//		cout<<FlightDate<<",";
		
		getline(input, Reporting_Airline, ',');
//		cout<<Reporting_Airline<<",";
		
		getline(input, OriginCityName, ',');
//		cout<<OriginCityName<<",";
		
		getline(input, DestCityName, ',');
//		cout<<DestCityName<<",";
		
		getline(input, nop, ',');
		if(nop != "\"\"")
		{
			stringstream str(nop);
			str >> DepDelay;
		}
		else
		{
			DepDelay=0;
		}
//		cout<<DepDelay<<",";
		
		getline(input, nop, ',');
		if(nop != "\"\"")
		{
			stringstream str(nop);
			str >> ArrDelay;
		}
		else
		{
			ArrDelay=0;
		}
//		cout<<ArrDelay<<endl;
		
		getline(input, nop, '\n');
		
		Node* newNode;
		newNode = new Node(FlightDate, Reporting_Airline, OriginCityName, DestCityName, DepDelay, ArrDelay);
		if(ArrDelay != INT_MAX)
		{
			tree.insert(newNode);
		}
	}
	
	return tree;
}

void ShortestDelay(AVL tree)
{
	system("cls");
	string org,dst;
	cout<<endl<<"Enter Origin City: ";
	cin>>org;
	cout<<endl<<"Enter Destination City: ";
	cin>>dst;
	cout<<endl<<"Flights with the shortest delay:"<<endl;
	tree.shortestDelay(org,dst);
	getch();
	return;
}

void FlightsOnDate(AVL tree)
{
	system("cls");
	string date;
	cout<<"Enter a date to extract flights from (YYYY-MM-DD): ";
	cin>>date;
	tree.flightsOnDate(date);
	getch();
	return;
}

void RecommendAirline(AVL tree)
{
	system("cls");
	AVL2 tree2;
	tree2 = tree.createAirlineTree();
	cout<<"Top airlines with shortest delay time:"<<endl<<endl;
	AVL3 tree3;
	tree3 = tree2.createTree();
	tree3.print();
	getch();
	return;
}

void menu()
{
	int choice;
	AVL tree;
	tree = loadData();
	do
	{
		system("cls");
		cout<<endl<<endl<<"----------------------------------------------------------------------------------------------------------------------"<<endl
						<<"\t\t\t\t\tMENU"<<endl<<endl;
		cout<<"Options:"<<endl<<endl<<"1. Show flights with shortest delay"<<endl<<"2. Show flights on a specific date"<<endl<<"3. Show recommended airlines"<<endl<<"4. Exit"<<endl<<"Enter your choice: ";
		cin>>choice;
	
		if(choice == 1)
		{
			ShortestDelay(tree);
		}
		else if(choice == 2)
		{
			FlightsOnDate(tree);
		}
		else if(choice == 3)
		{
			RecommendAirline(tree);
		}
		else if(choice == 4)
		{
			exit(0);
		}
		else
		{
			cout<<endl<<"Invalid choice";
		}
	}while(choice != 4);
	
	return;
}

int main()
{
	
	menu();
	
	
	return 0;
}
