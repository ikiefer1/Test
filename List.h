// List.h
// Isaiah Kiefer

#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <string>
#include <vector>
using std::vector;
using std::string;
using std::endl;
using std::cout;
template<class T>
struct BinNode {
	T data;
	BinNode<T>* left;
	BinNode<T>* right;
	int height;
	BinNode(T d) :data(d), left(nullptr), right(nullptr), height(1) {}
};
template<class T>
class List {
public:
	BinNode<T>* root;
	List();
	~List();
	void clear(BinNode<T>* t);
	void insert(string inWord);
	void insert(string inWord, BinNode<T>*& t);
	void delNode(string inWord, BinNode<T>*& t);
	//void printNode(void);
	int max(int a, int b);
	int height(BinNode<T>* t);
	int getBalance(BinNode<T>* t);
	void rightRotate(BinNode<T>*& k2);
	void leftRotate(BinNode<T>*& k2);
	void doubleRotateR(BinNode<T>*& k3);
	void doubleRotateL(BinNode<T>*& k3);
	BinNode<T>* find(string findWord);
	BinNode<T>* find(string findWord, BinNode<T>* t);
	BinNode<T>* findMin(BinNode<T>* t);
	BinNode<T>* findMax(BinNode<T>* t);
	//void sort();
	int size = 0;
	int foundComp = 0;
	long long int notComp = 0;
	int spellChecked = 0;
	int notSpelled = 0;
	int finalComp = 0;
	int tmpComp = 0;
	vector<string> text;
};

#include "List.cpp"
#endif
