#include <bits/stdc++.h>
int height(Treenode *root) {
    if (root == NULL)
        return 0;
    return max(height(root->left), height(root->right)) + 1;
}
 
int getcol(int h) {
    if (h == 1)
        return 1;
    return getcol(h - 1) + getcol(h - 1) + 1;
}
 
void printTree(int **M, Treenode *root, int col, int row, int height) {
    if (root == NULL)
        return;
    M[row][col] = root->data;
    printTree(M, root->left, col - pow(2, height - 2), row + 1, height - 1);
    printTree(M, root->right, col + pow(2, height - 2), row + 1, height - 1);
}
 
void TreePrinter(Tree tree) {
    int h = height(tree.root);
    int col = getcol(h);
    int **M = new int*[h];
    for (int i = 0; i < h; i++) {
        M[i] = new int[col];
    }
    printTree(M, tree.root, col / 2, 0, h);
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < col; j++) {
            if (M[i][j] == 0)
                cout << " " << " ";
            else
                cout << M[i][j] << " ";
        }
        cout << endl;
    }
}
// #include <vector>
// #include <iterator>
// #include <cstdio>
// #include <cstdlib>
// #include <algorithm>
// #include <iostream>
// #include <sstream>
// #include <string>
// #include <iomanip>
// #include <memory>
// #include <type_traits>

// template <class T>
// typename std::enable_if<std::is_integral<T>::value, bool>::type
// is_odd(T i) { return bool(i % 2); }

// template <class T>
// typename std::enable_if<std::is_integral<T>::value, bool>::type
// is_even(T i) { return !bool(i % 2); }

// int main(void)
// {
// 	int i;

// 	i = 1;
// 	std::cout << std::boolalpha;
// 	std::cout << is_odd(i) << std::endl;
// 	i = 2;
// 	std::cout << is_even(i) << std::endl;
// }