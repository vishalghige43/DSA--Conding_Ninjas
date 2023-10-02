template<typename T>
class BTNode{
    public:
    T data;
    BTNode *left;
    BTNode *right;

    BTNode(T data){
        this->data=data;
        this->left=NULL;
        this->right=NULL;
    }
    ~BTNode(){
        delete left;
        delete right;
    }
};