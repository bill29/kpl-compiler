typedef struct node
{
	char str[20];
	int count;
	int x[10];
	int y[10];
	struct node *left,*right;
}node;
void make_tree(node **root){
	*root=NULL;
}
int insert_tree(node **root,char word[20],int a,int b){
	if(*root!=NULL){
		if(strcmp((*root)->str,word)==0){
			(*root)->count++;
			(*root)->x[(*root)->count]=a;
			(*root)->x[(*root)->count]=b;
		}
		else if(strcmp((*root)->str,word)>0)
			insert_tree(&((*root)->right),word,a,b);
		else
			insert_tree(&((*root)->left),word,a,b);
	}
	else{
			(*root)=(node*)malloc(sizeof(node));
			if(*root==NULL)
				{
					printf("MEMORY ERROR \n");
					return -1;
				}
			strcpy((*root)->str,word);
			(*root)->x[0]=a;
			(*root)->y[0]=b;
			(*root)->left=NULL;
			(*root)->right=NULL;
			//printf("XXXXXXXXXXXX\n");
			//printf(" %s %d %d %d :\n",(*root)->str,(*root)->count,(*root)->x[0],(*root)->y[0]);
			return 1;
	}

}
void print_arr(int a[10],int b[10],int count){
	int i=0;
	while(i<=count){
		printf("(%d %d ) ",a[i],b[i]);
		i++;
	}
	printf("\n");

}
void print_inoder(node *root){
		if(root!=NULL){
		print_inoder(root->left);
		printf("%s %d ",root->str,root->count+1);
		print_arr(root->x,root->y,root->count);
		print_inoder(root->right);
	}
}