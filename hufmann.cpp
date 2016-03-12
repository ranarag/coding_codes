#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;


///////////////////////////////////////////////////////////
// STRUCTURE NODE
///////////////////////////////////////////////////////////
typedef struct node{
	char c;
	int freq;
	node* left;
    node* right;
	node(): c('\0'){
		left = NULL;
        right=NULL;
	}

}node;
///////////////////////////////////////////////////////////
// GLOBAL VARIABLES
///////////////////////////////////////////////////////////
vector <node *> Arr;
vector <int> pst;
///////////////////////////////////////////////////////////
// FUNCTION TO DECREASE VALUE
//////////////////////////////////////////////////////////

void decrease_val( int i, node* val){
	
    Arr[ i ] = val;
    while( i > 0 and Arr[ i/2 ]->freq > Arr[ i ]->freq)
    {
        swap(Arr[ i/2 ], Arr[ i ]);
        i = i/2;
    }


}
///////////////////////////////////////////////////////////
// FUNCTION TO INSERT VALUE
//////////////////////////////////////////////////////////
void insert_val(node* val){
	node *tmp=new node;
	tmp->freq = 99999999;
	//tmp->next = NULL;
	Arr.push_back(tmp);
	decrease_val(Arr.size() - 1, val);
}
///////////////////////////////////////////////////////////
// MIN HEAPIFY
///////////////////////////////////////////////////////////
void min_heapify(int i){
	int N=Arr.size()-1;
	int left = 2*i;
	int right = 2*i+1;
	int smallest;
	 if(left<= N and Arr[left]->freq < Arr[i]->freq )
          smallest = left;
    else
         smallest = i;
    if(right <= N and Arr[right]->freq < Arr[smallest]->freq )
        smallest = right;
    if(smallest != i )
    {
        swap (Arr[i] , Arr[smallest]);
        min_heapify (smallest);
    } 
}
///////////////////////////////////////////////////////////
// EXTRACT MINIMUM
///////////////////////////////////////////////////////////
node* extract_minimum ()
{
	int length = Arr.size()-1;
    

    
    node* min = Arr[0];
    //Arr.remove(min);
    Arr[0] = Arr[length];
    Arr.pop_back();
    length = length -1;
    min_heapify(0);
    return min;
}

///////////////////////////////////////////////////////////
// HUFFMANN
///////////////////////////////////////////////////////////
node* huffmann(char alpha[],int freq[],int n){

    node* tmp=new node;
    tmp->c = alpha[0];
    tmp->freq = freq[0]; 
    Arr.push_back(tmp);
    //delete [] tmp;
    for(int i=1;i<n;i++){
        node* tmp=new node;
        tmp->c = alpha[i];
        tmp->freq = freq[i];
        insert_val(tmp);
        //delete [] tmp;
    }
    for(int i=1;i<=n-1;i++){
        node *tmp = new node;
        tmp->left = extract_minimum();
        //cout<<"left = "<<tmp->left->c<<" "<<tmp->left->freq<<endl;
        tmp->right = extract_minimum();
         //cout<<"right = "<<tmp->right->c<<" "<<tmp->right->freq<<endl;
        tmp->freq = tmp->left->freq+tmp->right->freq;
        insert_val(tmp);
    }
    return extract_minimum();
}

///////////////////////////////////////////////////////////
// POST ORDER ROUTINE
///////////////////////////////////////////////////////////


void post(node *root){
    
    
   
    if(root->left){
        
        pst.push_back(0);
        post(root->left);
    }

    if(root->right){
        
        pst.push_back(1);
        post(root->right);
    }
    if(root->c=='\0'){
        //pst.pop_back();
        
    }
    else{
        cout<<root->c<<" = ";
        for(int i=0;i<pst.size();i++)cout<<pst[i];
            cout<<endl;
         
        
    }
    pst.pop_back();
    return;
}
 //////////////////////////////////////////////////////
 // DRIVER FUNCTION
 /////////////////////////////////////////////////////  
int main(void){
    int n;
    cout<<"Enter the no. of variables\n";
    cin>>n;
    char s[n];
    int freq[n];
    scanf("%s",s);
    for(int i=0;i<n;i++)cin>>freq[i];
   node* root= huffmann(s,freq,n);
   
    post(root);
   
}
