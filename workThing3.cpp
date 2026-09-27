#include <iostream>
#include <windows.h>
#include <cstdlib>
using namespace std;

struct node
{
	int data;
	node* next;
};

void gotoxy(int x, int y) {
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void insertAtFrontMenu() {
	cout << "Now inserting at the front of the list" << endl;
}

void insertAtEndMenu() {
	cout << "Now inserting at the end of the list" << endl;
}

void insertAfterValueMenu() {
	cout << "Now inserting after a specific value in the list" << endl;
}

void traverseListMenu() {
	cout << "Traversing the list:" << endl;
}

int main()
{
	int choice;
	node* head = NULL;

	do {
		gotoxy(40, 5);
		cout << "-------- <Menu> --------" << endl;
		gotoxy(40, 6);
		cout << "1. insert from the front of the list" << endl;
		gotoxy(40, 7);
		cout << "2. insert from the end of the list" << endl;
		gotoxy(40, 8);
		cout << "3. insert after the value" << endl;
		gotoxy(40, 9);
		cout << "4. traverse the list" << endl;
		gotoxy(40, 10);
		cout << "5. exit" << endl;
		gotoxy(40, 11);
		cout << "--------------------------" << endl;

		gotoxy(40, 13);
		cout << "Enter your choice: ";
		cin >> choice;

		system("cls");

		switch (choice)
		{
		case 1:
		{
			insertAtFrontMenu();

			int number_node;
			cout << "Enter your number: ";
			cin >> number_node;

			node* temp = new node;
			temp->data = number_node;
			temp->next = head;
			head = temp;

			cout << "Number inserted at the front." << endl;
			break;
		}

		case 2:
		{
			insertAtEndMenu();

			int number_node;
			cout << "Enter your number: ";
			cin >> number_node;

			node* temp = new node;
			temp->data = number_node;
			temp->next = NULL;

			if (head == NULL)
			{
				head = temp;
			}
			else
			{
				node* current = head;

				while (current->next != NULL)
				{
					current = current->next;
				}

				current->next = temp;
			}

			cout << "Number inserted at the end." << endl;
			break;
		}

		case 3:
		{
			insertAfterValueMenu();

			if (head == NULL)
			{
				cout << "The list is empty." << endl;
				break;
			}

			int value;
			int number_node;

			cout << "Enter the value to insert after: ";
			cin >> value;

			cout << "Enter your number: ";
			cin >> number_node;

			node* current = head;

			while (current != NULL && current->data != value)
			{
				current = current->next;
			}

			if (current == NULL)
			{
				cout << "Value not found in the list." << endl;
			}
			else
			{
				node* temp = new node;
				temp->data = number_node;
				temp->next = current->next;
				current->next = temp;

				cout << "Number inserted after " << value << "." << endl;
			}

			break;
		}

		case 4:
		{
			traverseListMenu();

			if (head == NULL)
			{
				cout << "The list is empty." << endl;
			}
			else
			{
				node* temp1 = head;

				while (temp1 != NULL)
				{
					cout << temp1->data;

					if (temp1->next != NULL)
					{
						cout << " -> ";
					}

					temp1 = temp1->next;
				}

				cout << endl;
			}

			break;
		}

		case 5:
			cout << "Exiting..." << endl;
			break;

		default:
			cout << "Invalid choice. Please try again." << endl;
		}

		if (choice != 5)
		{
			cout << endl;
			system("pause");
			system("cls");
		}

	} while (choice != 5);

	node* temp;

	while (head != NULL)
	{
		temp = head;
		head = head->next;
		delete temp;
	}

	return 0;
}
