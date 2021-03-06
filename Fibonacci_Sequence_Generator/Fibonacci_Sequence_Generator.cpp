// Fibonacci_Sequence_Generator.cpp : Defines the entry point for the console application.
//Author: Jason Lane Johnson

#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
//declare a data structure Node
struct Node
{
	//assign an int member of data structure
	int data;
	//assign pointer values allocating memory space for previous state and next state
	struct Node* next;
	struct Node* prev;
};
//Declare a Global Varaible
struct Node* head;

//Define a Method within the Node data structure GetNewNode(int x)
struct Node* GetNewNode(int x)
{
	//using malloc to allocate space for Node
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	//assign values to the Datastructure
	newNode->data = x;
	newNode->prev = NULL;
	newNode->next = NULL;
	return newNode;
};
//Define a Method within the Node data structure InsertAtHead(int x)
void InsertAtHead(int x)
{
	//newNode temp variable declared
	struct Node* newNode = GetNewNode(x);
	//test the list for an empty list
	if (head == NULL) {
		head = newNode;
		return;
	}
	head->prev = newNode;
	newNode->next = head;
	head = newNode;
}
//define a function Print()
void Print()
{
	struct Node* temp = head;
	printf("Forward: ");
	while (temp != NULL)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("\n");
}
//define a function ReversePrint()
void ReversePrint()
{
	struct Node* temp = head;
	if (temp == NULL) return; //empty list, exit
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	//Traversing Backward Using previous pointer
	printf("Reverse: ");
	while (temp != NULL)
	{
		printf("%d ", temp->data);
		temp = temp->prev;
	}
	printf("\n");
}
using namespace std;
int Fibonacci(int a, int b, int n);
int main()
{
	//create an empty list
	head = NULL;
	int Fibonacci_Number = 0;
	int increment = 0;
	int User_Input;

	//request user input for the total number of fibonacci numbers they would like to view.
	cout << "How Many Fibonacci Numbers would you like to know up to a maximum of 40: ";
	cin >> User_Input;
	cout << endl;

	//test if user input is less than 40.
	if (User_Input < 40)
	{
		while (increment < User_Input)
		{
			InsertAtHead(Fibonacci(Fibonacci_Number, Fibonacci_Number + 1, increment)); Print(); ReversePrint();
			increment++;
			cout << increment << ": " << Fibonacci(Fibonacci_Number, Fibonacci_Number + 1, increment) << endl << endl;
			;
		}
	}
	else
	{
		//return user to main menu if number is greater than 40.
		cout << "I'm Sorry, the computer has trouble processing numbers above 40.  Please enter a lower number." << endl << endl;
		main();
	}

	system("pause");
	return 0;
}

//initiate the fibonacci sequence
int Fibonacci(int a, int b, int n)
{
	if (n == 0)
	{
		return 0;
	}
	else if (n == 1 || n == 2)
	{
		return b;
	}
	else
	{
		return Fibonacci(a, b, n - 1) + Fibonacci(a, b, n - 2);
	}

}

