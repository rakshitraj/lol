/**
 * Array implemetation ob Binary tree
 * 
 * If parent is p and 
 * Array starts from 0 to n-1 then
 *      left_child  = (2*p) + 1
 *      right_child = (2*p) + 2
 * 
 * If parent is p and
 * Array stars from 1 to n; then
 *      left_child  = (2*p)
 *      right_child = (2*p) + 1
 * Saves clock cycles
 * 
 */

#include <iostream>
using namespace std;

char tree[10];

void root(char key){
    if( tree[0] != '\0') cout << "Tree already had root";
    else tree[0] = key;
}

void set_left(char key, int parent){
    if (tree[parent] == '\0')
    {
        cout << "\nCan't set child at " << (parent*2) + 1 << ", no parent found.";
    }
    else
    {
        tree[(parent*2)+1] = key;
    }
}

void set_right(char key, int parent)
{
    if (tree[parent] == '\0')   
    {
        cout << "\nCan't set child at " << (parent*2) + 2 << ", no parent found.";
    }
    else
    {
        tree[(parent * 2) + 2] = key;
    }
}

void printtree(){
    cout << endl;
    for(int i=0; i<10; i++){
        if(tree[i] != '\0') cout << tree[i];
        else cout << "-";
    }
}

int main()
{
    // array starting from 0 to n-1
    root('A');
    set_left('B',0);    //1
    set_right('C', 0);  //2
    set_left('D', 1);   //3
    set_right('E', 1);  //4
    set_left('F', 2);   //5
    set_right('G', 2);  //6

    printtree();

    return 0;
}