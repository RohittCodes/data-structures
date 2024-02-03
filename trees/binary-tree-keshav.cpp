#include <iostream>
#include <queue>
using namespace std;

class Node{
    public:
        int data;
        Node* left;
        Node* right;
        Node(int data){
            this->data=data;
            this->left=NULL;
            this->right=NULL;
        }
};

class Tree{
    public:
        Node* root;
        Tree(){
            root=NULL;
        }

        void insert(int data){
            Node* newNode = new Node(data);
            queue<Node*> q;
            q.push(root);
            while(!q.empty()){
                if(q.front()->left==NULL){
                    q.front()->left=newNode;
                    break;
                }
                if(q.front()->right==NULL){
                    q.front()->right=newNode;
                    break;
                }
                q.push(q.front()->left);
                q.push(q.front()->right);
                q.pop();
            }
        }

        void levelOrder(){
            queue<Node*> q;
            q.push(root);
            q.push(NULL);
            cout<<"Level order Traversing:\n";
            while(!q.empty()){
                Node* temp = q.front();
                q.pop();
                if(temp==NULL){
                    cout<<endl;
                    if(!q.empty()){
                        q.push(NULL);
                    }
                }
                else{
                    cout<<temp->data<<" ";
                    if(temp->left!=NULL){
                        q.push(temp->left);
                    }
                    if(temp->right!=NULL){
                        q.push(temp->right);
                    }
                }
            }
        }

        void inorder(Node* root){
            if(root=NULL){
                return;
            }
            inorder(root->left);
            cout<<root->data<<" ";
            inorder(root->right);
        }

        void preorder(Node* root){
            if(root=NULL){
                return;
            }
            cout<<root->data<<" ";
            preorder(root->left);
            preorder(root->right);
        }

        void postorder(Node* root){
            if(root=NULL){
                return;
            }
            postorder(root->left);
            postorder(root->right);
            cout<<root->data<<" ";
        }
};

int main(){
    Tree b;
    b.root = new Node(1);
    b.insert(5);
    b.insert(4);
    b.insert(3);
    b.insert(2);
    b.insert(1);
    b.levelOrder();
    cout<<"Done\n";
    b.inorder(b.root);
    b.postorder(b.root);
    b.preorder(b.root);
    return 0;
}