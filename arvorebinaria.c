#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<locale.h>
struct item{
	int cod;
};

typedef struct item Item;

struct node//cria um no
{
	Item item;
	struct node *left;
	struct node *right;
};

typedef struct node Node;

Node *treeInitialize(){// inicia uma arvore
	return NULL;
}

Item itemCreate(int cod){
	Item item;
	item.cod=cod;
	return item;
}
Node *treeInsert(Node *root, Item x){
	if(root ==NULL){//irá alocar um novo no apenas quando o local estiver vazio, ou seja o no pai ter um filho vazio
		Node *aux=(Node*)malloc(sizeof(Node));//aloca um novo no dinamicamente
		aux->item = x;//o x vai para o no que foi criado na linha acima
		aux->left=NULL;// como a arvore está vazia por ter acabado de inserir um novo no, a subarvore direita e esquerda serão null
		aux->right=NULL;
		return aux;//retorna o no
	}else{
		if(x.cod>=root->item.cod){// caso o valor do novo no seja maior ou igual ao no pai ele ira ser inserido a direita
			root->right=treeInsert(root->right, x);
		}else if(x.cod<root->item.cod){//o no sera inserido a esquerda
		root->left=treeInsert(root->left,x);
	}
	}
	return root;
}

void treePrint(Node *root){
	if(root!=NULL){
		printf(" %d ", root->item.cod);
		treePrint(root->left);
		treePrint(root->right);
	}
}
void treeFree(Node *root){
	if(root!=NULL){
		treeFree(root->left);
		treeFree(root->right);
		free(root);
	}
}
int main(){
	setlocale(LC_ALL,"Portuguese");
	Node *root=NULL;
	root=treeInsert(root, itemCreate(2));
	root=treeInsert(root, itemCreate(0));
	root=treeInsert(root, itemCreate(0));
	root=treeInsert(root, itemCreate(9));
	root=treeInsert(root, itemCreate(4));
	root=treeInsert(root, itemCreate(2));
	root=treeInsert(root, itemCreate(9));
	root=treeInsert(root, itemCreate(2));
	root=treeInsert(root, itemCreate(5));
	printf("A Pré-Ordem é:\n");
	treePrint(root);
	treeFree(root);
	return 0;
}
