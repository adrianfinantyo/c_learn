// C++ program for expression tree
#include<bits/stdc++.h>
using namespace std;

// An expression tree node
struct et
{
	char value;
	et* left, *right;
};

// A utility function to check if 'c'
// is an operator
bool isOperator(char c)
{
	if (c == '+' || c == '-' ||
			c == '*' || c == '/' ||
			c == '^')
		return true;
	return false;
}

// Utility function to do traversal
void preorder(et *t)
{
	if(t)
	{
		printf("%c ", t->value);
        preorder(t->left);
		preorder(t->right);
	}
}

void inorder(et *t)
{
	if(t)
	{
		inorder(t->left);
		printf("%c ", t->value);
		inorder(t->right);
	}
}

void postorder(et *t)
{
	if(t)
	{
        postorder(t->left);
		postorder(t->right);
        printf("%c ", t->value);
	}
}

// A utility function to create a new node
et* newNode(char v)
{
	et *temp = new et;
	temp->left = temp->right = NULL;
	temp->value = v;
	return temp;
};

// Returns root of constructed tree for given
// postfix expression
et* constructTree(char postfix[])
{
	stack<et *> st;
	et *t, *t1, *t2;

	// Traverse through every character of
	// input expression
	for (int i=0; i<strlen(postfix); i++)
	{
		// If operand, simply push into stack
		if (!isOperator(postfix[i]))
		{
			t = newNode(postfix[i]);
			st.push(t);
		}
		else // operator
		{
			t = newNode(postfix[i]);

			// Pop two top nodes
			t1 = st.top(); // Store top
			st.pop();	 // Remove top
			t2 = st.top();
			st.pop();

			// make them children
			t->right = t1;
			t->left = t2;

			// Add this subexpression to stack
			st.push(t);
		}
	}

	// only element will be root of expression
	// tree
	t = st.top();
	st.pop();

	return t;
}

// Driver program to test above
int main()
{
	char postfix[] = "ab+ef*g*-";
	et* r = constructTree(postfix);
    printf("prefix expression is \n");
	preorder(r);
	printf("\ninfix expression is \n");
	inorder(r);
    printf("\npostfix expression is \n");
    postorder(r);
    getchar();
	return 0;
}