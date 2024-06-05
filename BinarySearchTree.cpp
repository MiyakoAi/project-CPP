#include <iostream>
#include <queue>

using namespace std;

// 1. Struktur Node :
struct Node{
    int data;
    Node *left;
    Node *right;
};

Node *root=NULL, *n=NULL, *temp=NULL;

// 2. Pembuatan Node Baru:
Node *createNode(int data){
    n = new Node;
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}

// 3. Proses Insert node pada BST:
void insert(Node *&root, int data){
    if (root==NULL)
        root = createNode(data);
    else if (data <= root->data)
        insert(root->left, data);
    else if (data > root->data)
        insert(root->right, data);
}

// 4. Binary Tree Traversal menggunakan Level Order:
void levelOrder(Node *root){
    if (root==NULL) return;
        queue<Node*> q;
        q.push(root);
    while(!q.empty()){
        cout << q.front()->data << " ";
    if(q.front()->left != NULL)
        q.push(q.front()->left);
    if(q.front()->right != NULL)
        q.push(q.front()->right);
        q.pop();
    }
}

// 5. Binary Tree Traversal menggunakan Preorder:
void preOrder(Node *root){
    if (root==NULL) return;
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

// 6. Binary Tree Traversal menggunakan Inorder:
void inOrder(Node *root){
    if (root==NULL) return;
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

// 7. Binary Tree Traversal menggunakan Postorder:
void postOrder(Node *root){
    if (root==NULL) return;
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

// 8. Pencarian data pada BST:
bool cari(Node *root, int data){
    if (root==NULL)
        return false;
    else if(data < root->data)
        return cari(root->left, data);
    else if(data > root->data)
        return cari(root->right, data);
    else
        return true;
}

// 9. Mencari alamat memori node yang memiliki nilai minimum:
Node *cariMin(Node *root){
    if (root==NULL)
        return NULL;
    while(root->left != NULL)
        root = root->left;
    return root;
}

// 10. Penghapusan node pada BST:
void hapus(Node *&root, int data){
    if (root==NULL)
        return;
    else if(data < root->data)
        return hapus(root->left, data);
    else if(data > root->data)
        return hapus(root->right, data);
    else{

        // kasus I
        if (root->left == NULL && root->right == NULL){
            delete(root);
            root=NULL;
        }

        // kasus II
        else if (root->left == NULL){
            temp = root;
            root = root->right;
            delete(temp);
            temp=NULL;
        }
        else if (root->right == NULL){
            temp = root;
            root = root->left;
            delete(temp);
            temp=NULL;
        }

        // kasus III
        else{
            temp = cariMin(root->right);
            root->data = temp->data;
            hapus(root->right, root->data);
        }
    }
}

int main(){
    int nilai, pilihan, subpil;

    do{
        cout << "Menu" << endl;
        cout << "1. Memasuukan Node Baru" << endl;
        cout << "2. Insert Node" << endl;
        cout << "3. mencari Node" << endl;
        cout << "4. Hapus Node" << endl;
        cout << "5. Binary Tree Traversal" << endl;
        cout << "6. Keluar" << endl;
        cout << "Masukkan Pilihan : ";
        cin >> pilihan;
        system("cls");
        cout << endl;

        if(pilihan == 1){
            system("cls");
            cout << "1. Membuat node baru" << endl;
            cout << "====================" << endl;
            cout << "Masukkan Node Baru : ";
            cin >> nilai;
            createNode(nilai);
            cout << "Node " << nilai << " berhasil dimasuukan kedalam node" << endl;
        }

        else if(pilihan == 2){
            system("cls");
            cout << "Insert Node" << endl;
            cout << "===========" << endl;
            cin >> nilai;
            insert(root, nilai);
            cout << "Node " << nilai << " berhasil di insert" << endl;
        }

        else if (pilihan == 3){
            system("cls");
            int pilcar;
            cout << "Mencari Node" << endl;
            cout << "============" << endl;
            cout << "Masukkan Node yang akan dicari : ";
            cari(root, nilai);
            cin >> nilai;
            cin >> pilcar;
        }

        else if(pilihan == 4){
            system("cls");
            cout << "Hapus Data Node" << endl;
            cout << "===============" << endl;
            cout << "Masukkan Node yang ingin dihapus : ";
            cin >> nilai;
            hapus(root, nilai);
            cout << "Node " << nilai << " Berhasil dihapus" << endl; 
        }

        else if(pilihan == 5){
            int pilsea;
            cout << "Binary Tree traversal" << endl;
            cout << "=====================" << endl;
            cout << endl;
            cout << "Menu" << endl;
            cout << "1. Binary Tree Traversal Level Order" << endl;
            cout << "2. Binary Tree Traversal Preorder" << endl;
            cout << "3. Binary Tree Traversal Inorder" << endl;
            cout << "4. Mencari Nilai Minumun Binary Tree Traversal" << endl;
            cout << "5. Binary Tree Traversal Postorder" << endl;
            cout << "Masukkan Pilihan : ";
            cin >> pilsea;

            if(pilsea == 1){
                cout << "Binary Tree Traversal Level Order" << endl;
                cout << "=================================" << endl;
                levelOrder(root);
                cout << endl;
            }

            else if(pilsea == 2){
                cout << "Binary Tree Traversal Level Preorder" << endl;
                cout << "=================================" << endl;
                preOrder(root);
                cout << endl;
            }

            else if(pilsea == 3){
                cout << "Binary Tree Traversal Inorder" << endl;
                cout << "=================================" << endl;
                inOrder(root);
                cout << endl;
            }

            else if(pilsea == 4){
                cout << "Mencari nilai minimun Binary Tree Traversal" << endl;
                cout << "=================================" << endl;
                cariMin(root);
                cout << endl;
            }

            else if(pilsea == 5){
                cout << "Binary Tree Traversal Postorder" << endl;
                cout << "=================================" << endl;
                postOrder(root);
                cout << endl;
            }

            else(pilsea);
        }

    }while (pilihan !=6);
    cout << endl;
    cout << "|================|" <<endl;
    cout << "| Program Keluar |" << endl;
    cout << "|  Terima Kasih  |" << endl;
    cout << "|================|";

}