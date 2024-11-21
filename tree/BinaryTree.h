#pragma once
#include <iostream>
using namespace std;
template <typename T>
struct TreeNode {
	T value;
	TreeNode<T>* left;
	TreeNode<T>* right;
	TreeNode(T value,TreeNode<T>* left, TreeNode<T>* right): value(value),left(left),right(right){}
};
template <typename T>
class BinaryTree
{
private:
	TreeNode<T>* root;
public:
	BinaryTree(T* arr, int size);
	void insert(T value, TreeNode<T>* root);
	void remove(T value);
	TreeNode<T>* find(T value, TreeNode<T>* root);
	void print(TreeNode<T>* root);
	TreeNode<T>* getRoot();
	void clearMemory(TreeNode<T>* root);
	~BinaryTree();
};

template<typename T>
inline BinaryTree<T>::BinaryTree(T* arr, int size)
{
	this->root = new TreeNode<T>(arr[0], nullptr, nullptr);
	for (int i = 1; i < size; i++) {
		insert(arr[i], this->root);
	}
}

template<typename T>
inline void BinaryTree<T>::insert(T value, TreeNode<T>* root)
{
	if (value > root->value) {
		if (root->right == nullptr) {
			root->right = new TreeNode<T>(value,nullptr,nullptr);
			return;
		}
		return insert(value, root->right);
	}
	else {
		if (root->left == nullptr) {
			root->left = new TreeNode<T>(value,nullptr,nullptr);
			return;
		}
		return insert(value, root->left);
	}
}

template<typename T>
inline void BinaryTree<T>::remove(T value)
{
	TreeNode<T>* root = this->root;
	TreeNode<T>* buf=nullptr;
	bool flag = true;
	while (flag) {
		if (value > root->value) {
			if (value == root->right->value) {
				buf = root->right;
				flag = false;
			}
			else {
				root = root->right;
				continue;
			}
		}
		//else if (root->value == value) {}//lkfljsls
		else {
			if (value == root->left->value) {
				buf = root->left;
				flag = false;
			}
			else {
				root = root->left;
				continue;
			}
		}
	}
	//if (buf->left == nullptr && buf->right == nullptr) {
	//	if (root->left->value = value) {
	//		root->left = nullptr;
	//	}
	//	if (root->right->value == value) {
	//		root->right = nullptr;
	//	}
	//}
	//else if (buf->left == nullptr || buf->right == nullptr) {
	//	if (buf->left == nullptr) {

	//	}
	//}
	if (buf->right == nullptr) {
		root->left = buf->left;
	}
	else {
		root->left = buf->right;
		if (buf->right->left != nullptr) {
			TreeNode<T>* node = buf->right->left;
			while (node->left != nullptr) {
				node = node->left;
			}
			node->left = buf->left;
		}
		else {
			buf->right->left = buf->left;
		}
	}
}

template<typename T>
inline TreeNode<T>* BinaryTree<T>::find(T value, TreeNode<T>* root)
{
	if (value == root->value) { return root; }
	else if (value > root->value) {
		find(value, root->right);
	}
	else if (value<root->value){
		find(value, root->left);
	}
	else {
		return nullptr;
	}
}

template<typename T>
inline void BinaryTree<T>::print(TreeNode<T>* root)
{
	if (root == nullptr) {
		return;
	}
	cout << root->value << " " << endl;
	print(root->left);
	print(root->right);
}

template<typename T>
inline TreeNode<T>* BinaryTree<T>::getRoot()
{
	return this->root;
}

template<typename T>
inline void BinaryTree<T>::clearMemory(TreeNode<T>* root)
{
	if (root == nullptr) {
		return;
	}
	clearMemory(root->right);
	clearMemory(root->left);
	delete root;
}


template<typename T>
inline BinaryTree<T>::~BinaryTree()
{
	clearMemory(this->root);
}
