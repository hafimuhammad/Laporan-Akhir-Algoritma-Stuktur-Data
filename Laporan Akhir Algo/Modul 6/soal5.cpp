#include <iostream>
#include <string>
#include "RedBlackTree.h"

using namespace std;

void cetakPreorder(const RedBlackTree::Node* node, bool &first) {
    if (node->isNil) return;

    if (!first) cout << " ";
    cout << node->key;
    first = false;

    cetakPreorder(node->left, first);
    cetakPreorder(node->right, first);
}

void cetakInorder(const RedBlackTree::Node* node, bool &first) {
    if (node->isNil) return;

    cetakInorder(node->left, first);

    if (!first) cout << " ";
    cout << node->key;
    first = false;

    cetakInorder(node->right, first);
}

void cetakPostorder(const RedBlackTree::Node* node, bool &first) {
    if (node->isNil) return;

    cetakPostorder(node->left, first);
    cetakPostorder(node->right, first);

    if (!first) cout << " ";
    cout << node->key;
    first = false;
}

int main() {
    RedBlackTree rbt;
    int N;
    if (!(cin >> N)) return 0;

    for (int i = 0; i < N; i++) {
        int angka;
        cin >> angka;
        if (!rbt.contains(angka)) {
            rbt.insert(angka);
        }
    }

    int Q;
    if (!(cin >> Q)) return 0;
    for (int i = 0; i < Q; i++) {
        string tipeQuery;
        cin >> tipeQuery;

        bool first = true;
        if (tipeQuery == "PREORDER") {
            cout << "[Preorder] : ";
            cetakPreorder(rbt.root(), first);
            cout << endl;
        } else if (tipeQuery == "INORDER") {
            cout << "[Inorder]  : ";
            cetakInorder(rbt.root(), first);
            cout << endl;
        } else if (tipeQuery == "POSTORDER") {
            cout << "[Postorder] : ";
            cetakPostorder(rbt.root(), first);
            cout << endl;
        } else if (tipeQuery == "ALL") {
            first = true;
            cout << "[Preorder] : ";
            cetakPreorder(rbt.root(), first);
            cout << endl;

            first = true;
            cout << "[Inorder]  : ";
            cetakInorder(rbt.root(), first);
            cout << endl;

            first = true;
            cout << "[Postorder] : ";
            cetakPostorder(rbt.root(), first);
            cout << endl;
        } else {
            cout << "Query tidak dikenali: " << tipeQuery << endl;
        }
    }

    return 0;
}