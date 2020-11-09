#include <iostream>
#include <string>

using namespace std;

struct TreeNode
{
  string titles;
  struct TreeNode* left;
  struct TreeNode* right;

  TreeNode(string t) 
    { 
        titles = t; 
        left = nullptr; 
        right = nullptr; 
    } 

};

 void in_order_tree_walk(TreeNode* root)
    {
      if(root != nullptr)
      {
        in_order_tree_walk(root->left);
        cout << root->titles << '\n';
        in_order_tree_walk(root->right);
      }
    }

TreeNode* insertValue(TreeNode* root, string newValue)
{
  if(root == nullptr)
  {
    root = new TreeNode(newValue);
    return root;
  }
  if(root->titles > newValue)
  {
    root->left = insertValue(root->left, newValue);
  }
 else {
  root->right= insertValue(root->right, newValue);
}
  return root;
}

string leftTraversal(TreeNode* root)
{

  root = root->left;
  while(root->right != nullptr)
  {
    root = root->right;
  }
  return root->titles;
}

string rightTraversal(TreeNode* root)
{

  root = root->right;
  while(root->left != nullptr)
  {
    root = root->left;
  }
  
  return root->titles;
}


TreeNode* deleteValue(TreeNode* root, string value)
{
   if(root == nullptr)
   {
     return root;
   }
    if(root->titles > value)
   {
     root->left = deleteValue(root->left,value);
   }
   else if(root->titles < value)
   {
     root->right = deleteValue(root->right,value);
   }
   else{
     if(root->left == nullptr && root->right ==nullptr)
     {
       root = nullptr;
     }
     else if(root->left != nullptr)
     {
        root->titles = leftTraversal(root);
       root->left = deleteValue(root->left, root->titles);
     }
     else{
        
        root->titles = rightTraversal(root);
       root->right = deleteValue(root->right, root->titles);
     }
   }
   return root;
}

int main() {
  struct TreeNode* root = new TreeNode("Operating Officer"); 
  root->left = new TreeNode("Commercial Officer"); 
    root->right = new TreeNode("Technology Officer"); 

    root->left->left = new TreeNode("Automation Officer");
     root->left->right = new TreeNode("Financial Officer");
      root->left->right->left = new TreeNode("Data Officer");
       root->left->right->right = new TreeNode("Information Officer");

  root->right->left = new TreeNode("Security Officer"); 
  root->right->right = new TreeNode("UserExperience Officer"); 

  in_order_tree_walk(root);
  cout <<'\n';
  insertValue(root, "Knowledge Officer");
  insertValue(root, "Talent Officer");
  cout << "Succesfully inseted Knowledge and Talent Officer. The final tree structure is: " << '\n';
  in_order_tree_walk(root);
   cout <<'\n';
deleteValue(root, "Security Officer");
cout << "Succesfully deleted Security Officer. The final tree structure is: " << '\n';
  in_order_tree_walk(root);
}
