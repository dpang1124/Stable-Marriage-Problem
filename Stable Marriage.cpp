/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include<iostream>
using namespace std;

//current match: Man    Woman
//               0      2
//               1      0
//               2      1

bool ok(int q[],int col){
int mp[3][3]={{0,2,1},
              {0,2,1},
              {1,2,0}};
              
int wp[3][3]={{2,1,0},
              {0,1,2},
              {2,0,1}};
              
int match[3] = {2, 0, 1};

for(int i=0; i<col; i++){
    
if(q[col]==q[i])
return false;
if(mp[i][q[col]] < mp[i][q[i]] and wp[q[col]][i] < wp[q[col]][col])
return false;
if(mp[col][q[i]] < mp[col][q[col]] and wp[q[i]][col]<wp[q[i]][i])
return false;
}
return true;
}


void backtrack(int &col){
col--;
if(col==-1)   
return;
}


void print(int q[]){
static int count=0;
cout << "Solution#" << ++count<< ":" << endl << "Men\tWomen"<< endl;
for(int i=0; i<3; i++){
cout << i << "\t" << q[i] << endl;
}
cout<<endl;
}


int main(){
int q[3]= {}, col=0;
q[0]=0;
bool from_backtrack=false;

while(true){
while(col<3){
if(!from_backtrack)
q[col]=-1;
from_backtrack=false;

while(q[col]<3){
q[col]++;

while(q[col]==3){					
backtrack(col);
q[col]++;
}

if(ok(q,col)){
break;
}

}	

col++;
}		
print(q);
backtrack(col);
from_backtrack=true;
}

return 0;
}