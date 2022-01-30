class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution1 {
public:
    Node* connect(Node* root) {
        if (root == nullptr) 
            return root;
        
        queue<Node*> q;
        q.push(root);
        
        while (!q.empty()) {
            
            int size = q.size();
            
            for (int i = 0; i < size; i++) {
                
                Node* temp_node = q.front();
                q.pop();
                
                if (i < size - 1)
                    temp_node->next = q.front();
                
                if (temp_node->left != nullptr)
                    q.push(temp_node->left);
                
                if (temp_node->right != nullptr)
                    q.push(temp_node->right);
                
            }
        }
        
        return root;
    }   
};

class Solution2 {
public:
    Node* connect(Node* root) {
        
        if (root == nullptr)
            return root;
        
        Node *leftmost = root;
        
        while(leftmost->left != nullptr) {
            
            Node *head = leftmost;
            
            while(head != nullptr) {
                //Connection 1
                head->left->next = head->right;

                // Connection 2
                if (head->next != nullptr) {
                    head->right->next = head->next->left;
                }

                head = head->next;
            }
            
            leftmost = leftmost->left;
        }
        
        return root;
    }   
};
