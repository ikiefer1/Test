//List.cpp
//Isaiah Kiefer
#include <iostream>
#include "List.h"
#include <string>

using std::string;
using std::endl;
using std::cout;
#ifndef LIST_HC
#define LIST_HC
template<class T>
List<T>::List()
{
	root = nullptr;
}
template<class T>
List<T>::~List()
{
	clear(root);
}
template<class T>
void List<T>::clear(BinNode<T>* t)
{
	if (t == nullptr)
	{
		return;
	}
	else
	{
		clear(t->left);
		clear(t->right);
		delete(t);
	}
}

template<class T>
void List<T>::insert(string inWord)
{
	insert(inWord, root);
}
template<class T>
void List<T>::insert(string inWord, BinNode<T>*& t)
{
	
	if (t == nullptr)
	{
		t = new BinNode<T>(inWord);
		size++;
		
	}
	else if (inWord.compare(t->data) < 0)
	{
		
		insert(inWord, t->left);/*
		if (height(t->left) - height(t->right) == 2)
		{
			if (inWord < t->left->data)
			{
				 rightRotate(t);
			}
			else
			{
				 doubleRotateR(t);
			}
		}
		*/
	}
	else if (inWord.compare(t->data) > 0)
	{
		
		insert(inWord, t->right);
		/*if (height(t->right) - height(t->left) == 2)
		{
			if (inWord < t->right->data)
			{
				leftRotate(t);
			}
			else
			{
				doubleRotateL(t);
			}
		}*/
	}
	t->height = 1 + max(height(t->left), height(t->right));
	int balance = getBalance(t);
	if (balance > 1 && inWord < t->left->data)
	{
		rightRotate(t);
	}
	else if (balance < -1 && inWord > t->right->data)
	{
		leftRotate(t);
	}
	else if (balance > 1 && inWord > t->left->key)
	{
		doubleRotateR(t);
	}
	else if (balance < -1 && inWord < t->right->data)
	{
		doubleRotateL(t);
	}
	
}
template<class T>
void List<T>::delNode(string inWord, BinNode<T>*& t)
{
	if (t == nullptr)
	{
		return;
	}
	else if (inWord.compare(t->data) < 0)
	{
		remove(inWord, t->left);
	}
	else if (inWord.compare(t->data) > 0)
	{
		remove(inWord, t->right);
	}
	else {
		BinNode<T>* oldNode;
		if (t->left == nullptr)
		{
			oldNode = t;
			t = t->right;
			delete oldNode;
			return;
		}
		else if (t->right == nullptr)
		{
			oldNode = t;
			t = t->left;
			delete oldNode;
			return;
		}
		else {
			oldNode = findMin(t->right);
			t->data = oldNode->data;
			remove(t->data, t->right);
		}
	}
}
template<class T>
BinNode<T>* List<T>::find(string findWord)
{
	return find(findWord, root);
}
template<class T>
BinNode<T>* List<T>::find(string findWord, BinNode<T>* t)
{
	while (t != nullptr)
	{
		if (findWord.compare(t->data) < 0)
		{
			tmpComp++;
			return find(findWord, t->left);
		}
		else if (findWord.compare(t->data) > 0)
		{
			tmpComp++;
			return find(findWord, t->right);
		}
		else
		{
			tmpComp++;
			spellChecked++;
			foundComp += tmpComp;
			tmpComp = 0;
			return t;
		}
	}
		notSpelled++;
		notComp += tmpComp;
		text.push_back(findWord);
		tmpComp = 0;
		return nullptr;
	
}
template<class T>
BinNode<T>* List<T>::findMin(BinNode<T>* t)
{
	if (t == nullptr)
	{
		return nullptr;
	}
	else if (t->left == nullptr)
	{
		return t;
	}
	else {
		return findMin(t->left);
	}
}
template<class T>
BinNode<T>* List<T>::findMax(BinNode<T>* t)
{
	if (t == nullptr)
	{
		return nullptr;
	}
	else if (t->right == nullptr)
	{
		return t;
	}
	else {
		return findMax(t->right);
	}
}
template<class T>
int List<T>::max(int a, int b)
{
	return (a > b) ? a : b;
}
template<class T>
int List<T>::height(BinNode<T>* t)
{
	if (t == nullptr)
	{
		return 0;
	}
	return t->height;
}
template<class T>
int List<T>::getBalance(BinNode<T>* t)
{
	if (t == nullptr)
	{
		return 0;
	}
	return height(t->left) - height(t->right);
}
template<class T>
void List<T>::rightRotate(BinNode<T>*& k2)
{
	BinNode<T>* k1 = k2->left;
	k2->left = k1->right;
	k1->right = k2;
	k2->height = max(height(k2->left), height(k2->right)) + 1;
	k1->height = max(height(k1->right), k2->height) + 1;
	k2 = k1;

}
template<class T>
void List<T>::leftRotate(BinNode<T>*& k2)
{
	BinNode<T>* k1 = k2->right;
	k2->right = k1->left;
	k1->left = k2;
	k2->height = max(height(k2->left), height(k2->right)) + 1;
	k1->height = max(height(k2->right), k2->height) + 1;
	k2 = k1;
}
template<class T>
void List<T>::doubleRotateR(BinNode<T>*& k3)
{
	leftRotate(k3->left);
	rightRotate(k3);
}
template<class T>
void List<T>::doubleRotateL(BinNode<T>*& k3)
{
	rightRotate(k3->right);
	leftRotate(k3);
}

/*template<class T>
void List<T>::printNode(void)
{
	if(root!=nullptr)
	{
		if(root->left!=nullptr)
		printNode(root->left);
		printNode(root->right);
		cout<<root->data;
	}

}

/*template<class T>
void List<T>::sort()
{
	string tempTest;

	for (node<T>* tmp = head; tmp != nullptr; tmp = tmp->next)
	{
		for (node<T>* tmp2 = tmp->next; tmp2 != nullptr; tmp2 = tmp2->next)
		{
			if (tmp->data.size() > tmp2->data.size())
			{
				tempTest = tmp2->data;
				tmp2->data = tmp->data;
				tmp->data = tempTest;
			}
		}
	}
	return;
}
*/
#endif