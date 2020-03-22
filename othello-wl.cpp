

#include <iostream>
#include <unistd.h>
using namespace std;
void display(char board[][8]);
int user_insertion_X();
int user_insertion_Y();
int search_left_HR(char [][8],char a,char b,int i,int j);
int search_right_HR(char [][8],char a,char b,int i,int j);
int search_VD(char board[][8],char a,char b,int i,int j);
int search_VU(char board[][8],char a,char b,int i,int j);
int search_URD(char board[][8],char a,char b,int i,int j);
int search_ULD(char board[][8],char a,char b,int i,int j);
int search_DLD(char board[][8],char a,char b,int i,int j);
int search_DRD(char board[][8],char a,char b,int i,int j);
int C_search_right_HR(char board[][8],char a,char b,int i,int j);
int C_search_left_HR(char board[][8],char a,char b,int i,int j);
int C_search_VU(char board[][8],char a,char b,int i,int j);
int C_search_VD(char board[][8],char a,char b,int i,int j);
int C_search_URD(char board[][8],char a,char b,int i,int j);
int C_search_ULD(char board[][8],char a,char b,int i,int j);
int C_search_DLD(char board[][8],char a,char b,int i,int j);
int C_search_DRD(char board[][8],char a,char b,int i,int j);
void winner(char board[][8]);
int main()
{
    int i,j,x,y,count,flag=0,temp=0,a1,a2,a3,a4,a5,a6,a7,a8,test=0;
    char board[8][8];
    for(i=0;i<8;i++)
    {
        for(j=0;j<8;j++)
        {
            board[i][j] = '.';
        }
            
    }
    board[3][3] = 'O';
    board[3][4] = 'X';
    board[4][3] = 'X';
    board[4][4] = 'O';
   
    while(1)
    {
        test++;
        display(board);
        while(1)  //Check if the coordinates entered are valid by the user
        {
            x = user_insertion_X();
            y = user_insertion_Y();
            if(board[x][y]=='.' && x<8 && y<8 && x>=0 && y>=0)
            {
                board[x][y] = 'O';
                search_left_HR(board,'O','X',x,y);
                search_right_HR(board,'O','X',x,y);
                search_VD(board,'O','X',x,y);
                search_VU(board,'O','X',x,y);
                search_URD(board,'O','X',x,y);
                search_URD(board,'O','X',x,y);
                search_ULD(board,'O','X',x,y);
                search_DLD(board,'O','X',x,y);
                search_DRD(board,'O','X',x,y);
                cout<<endl;
                cout<<endl;
                display(board);
            break;
            }
            else
                cout<<"You entered wrong coordinates!!"<<endl;
        }
        cout<<"\nPlease be patient I am making my move!!";
        cout<<endl;
        usleep(4000000);
        cout<<"MY move----\n";
        usleep(1000000);
        cout<<endl;
        flag=0;
        temp=0;
        while(1)
        {
            for(i=0;i<8;i++)
            {
                for(j=0;j<8;j++)
                {
                    if(board[i][j]=='X')
                    {
                        a1 = C_search_right_HR(board,'O','.',i,j);
                        if(a1==1)
                        {
                            flag=1;
                            break;
                        }
                        else
                        {
                            a2 = C_search_left_HR(board,'O','.',i,j);
                            if(a2==1)
                            {
                                flag=1;
                                break;
                            }
                            else
                            {
                                a3 = C_search_VU(board,'O','.',i,j);
                                if(a3==1)
                                {
                                    flag=1;
                                    break;
                                }
                                else
                                {
                                    a4 = C_search_VD(board,'O','.',i,j);
                                    if(a4==1)
                                    {
                                        flag=1;
                                        break;
                                    }
                                    else
                                    {
                                        a5 = C_search_URD(board,'O','.',i,j);
                                        if(a5==1)
                                        {
                                            flag=1;
                                            break;
                                        }
                                        else
                                        {
                                            a6 = C_search_ULD(board,'O','.',i,j);
                                            if(a6==1)
                                            {
                                                flag=1;
                                                break;
                                            }
                                            else
                                            {
                                                a7 = C_search_DLD(board,'O','.',i,j);
                                                if(a7==1)
                                                {
                                                    flag=1;
                                                    break;
                                                }
                                                else
                                                {
                                                    a8 = C_search_DRD(board,'O','.',i,j);
                                                    if(a8==1)
                                                    {
                                                        flag=1;
                                                        break;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                                
                            }
                        }
            
                    }
                }
                if(flag==1)
                {
                    temp=1;
                    break;
                }
            }
            if(temp==1)
                break;
        }
        cout<<endl;
        if(test==29)
        {
            winner(board);
            break;
        }
        
    }
    return 0;
}

//Function to take X-coordinate from user
int user_insertion_X()
{
    int x;
    cout<<"Enter the row number: ";
    cin>>x;
    return x;
}

//Function to take Y-coordinate from user
int user_insertion_Y()
{
    int y;
    cout<<"Enter the column number: ";
    cin>>y;
    return y;
}

//flipping towards right
int search_left_HR(char board[][8],char a,char b,int i,int j)
{
    int k,count=0;
    for(k=j-1;k>=0;k--)
    {
        if(board[i][k]==b)
        {
            count=count+1;
        }
        else if(board[i][k]==a && count>0)
        {
            for(int m=k;m<j;m++)
                board[i][m]= a;
            return count;
        }
        else
        {
            return count;
        }
        
    }
    return count;
}


//flipping towards left
int search_right_HR(char board[][8],char a,char b,int i,int j)
{
    int m,k,count=0;
    for(m=j+1;m<8;m++)
    {
        if(board[i][m]==b)
            count=count+1;
        else if(board[i][m]==a && count>0)
        {
            for(k=m;k>=j;k--)
                board[i][k]=a;
            return count;
        }
        else
        {
            return count;
        }
    }
    return count;
}

//flipping downwards
int search_VD(char board[][8],char a,char b,int i,int j)
{
    int m,k,count=0;
    for(k=i+1;k<8;k++)
    {
        if(board[k][j]==b)
            count=count+1;
        else if(board[k][j]==a)
        {
            for(m=k;m>i;m--)
                board[m][j]=a;
            return count;
        }
        else{
            return count;
        }
    }
    return count;
}

//flipping upwards
int search_VU(char board[][8],char a,char b,int i,int j)
{
    int m,k,count=0;
    for(k=i-1;k>=0;k--)
    {
        if(board[k][j]==b)
            count=count+1;
        else if(board[k][j]==a && count>0)
        {
            for(m=k;m<i;m++)
                board[m][j]=a;
            return count;
        }
        else
            return count;
    }
    return count;
}

//flipping upward right diagonal
int search_URD(char board[][8],char a,char b,int i,int j)
{
    int m,n,k,l,count=0;
    for(m=i-1,n=j+1;m>=0,n<8;m--,n++)
    {
        if(board[m][n]==b)
            count=count+1;
        else if(board[m][n]==a && count>0)
        {
            for(k=m,l=n;k<i,l>j;k++,l--)
                board[k][l]=a;
            return count;
        }
        else
            return count;
    }
    return count;
}

//flipping downward right diagonal
int search_DRD(char board[][8],char a,char b,int i,int j)
{
    int m,n,k,l,count=0;
    for(m=i+1,n=j+1;m<8,n<8;m++,n++)
    {
        if(board[m][n]==b)
            count=count+1;
        else if(board[m][n]==a && count>0)
        {
            for(k=m,l=n;k>i,l>j;k--,l--)
                board[k][l]=a;
            return count;
        }
        else
            return count;
    }
    return count;
}


//flipping downward left diagonal
int search_DLD(char board[][8],char a,char b,int i,int j)
{
    int m,n,k,l,count=0;
    for(m=i+1,n=j-1;m<8,n>=0;m++,n--)
    {
        if(board[m][n]==b)
            count=count+1;
        else if(board[m][n]==a && count>0)
        {
            for(k=m,l=n;k>i,l<j;k--,l++)
                board[k][l]=a;
            return count;
        }
        else
            return count;
    }
    return count;
}

//flipping upward left diagonal
int search_ULD(char board[][8],char a,char b,int i,int j)
{
    int m,n,k,l,count=0;
    for(m=i-1,n=j-1;m>=0,n>=0;m--,n--)
    {
        if(board[m][n]==b)
            count=count+1;
        else if(board[m][n]==a && count>0)
        {
            for(k=m,l=n;k<i,l<j;k++,l++)
                board[k][l]=a;
            return count;
        }
        else
            return count;
    }
    return count;
}

void display(char board[][8])
{
    int i,j;
    cout<<"  ";
    for(i=0;i<8;i++)
        cout<<i<<" ";
    cout<<"\n";
    for(i=0;i<8;i++)
    {
        cout<<i<<" ";
        for(j=0;j<8;j++)
        {
            cout<<board[i][j]<<" ";
        }
        cout<<"\n";
    }
}


//Computer turn code

int C_search_right_HR(char board[][8],char a,char b,int c,int d)
{
    int k,m,count=0;
    for(k=d+1;k<8;k++)
    {
        if(board[c][k]==a)
            count=count+1;
        else if(board[c][k]==b && count>0)
        {
            for(m=k;m>d;m--)
                board[c][m] = 'X';
            search_left_HR(board,'X','O',c,m);
            search_VD(board,'X','O',c,k);
            search_VU(board,'X','O',c,k);
            search_URD(board,'X','O',c,k);
            search_URD(board,'X','O',c,k);
            search_ULD(board,'X','O',c,k);
            search_DLD(board,'X','O',c,k);
            search_DRD(board,'X','O',c,k);
            return 1;
        }
        else
            return 0;
    }
    return 0;
}

int C_search_left_HR(char board[][8],char a,char b,int c,int d)
{
    int k,m,count=0;
    for(k=d-1;k>=0;k--)
    {
        if(board[c][k]==a)
            count=count+1;
        else if(board[c][k]==b && count>0)
        {
            for(m=k;m<d;m++)
                board[c][m] = 'X';
            search_right_HR(board,'X','O',c,k);
            search_VD(board,'X','O',c,k);
            search_VU(board,'X','O',c,k);
            search_URD(board,'X','O',c,k);
            search_URD(board,'X','O',c,k);
            search_ULD(board,'X','O',c,k);
            search_DLD(board,'X','O',c,k);
            search_DRD(board,'X','O',c,k);
            return 1;
        }
        else
            return 0;
    }
    return 0;
    
}

int C_search_VU(char board[][8],char a,char b,int c,int d)
{
    int k,m,count=0;
    for(k=c+1;k<8;k++)
    {
        if(board[k][d]==a)
            count=count+1;
        else if(board[k][d]==b && count>0)
        {
            for(m=k;m>c;m--)
                board[m][d]='X';
            search_left_HR(board,'X','O',c,k);
            search_VD(board,'X','O',c,k);
            search_right_HR(board,'X','O',c,k);
            search_URD(board,'X','O',c,k);
            search_URD(board,'X','O',c,k);
            search_ULD(board,'X','O',c,k);
            search_DLD(board,'X','O',c,k);
            search_DRD(board,'X','O',c,k);
            return 1;
        }
        else
            return 0;
    }
    return 0;
}

int C_search_VD(char board[][8],char a,char b,int c,int d)
{
    int k,m,count=0;
    for(k=c-1;k>=0;k--)
    {
        if(board[k][d]==a)
            count=count+1;
        else if(board[k][d]==b && count>0)
        {
            for(m=k;m<c;m++)
                board[m][d]='X';
            search_left_HR(board,'X','O',c,k);
            search_right_HR(board,'X','O',c,k);
            search_VU(board,'X','O',c,k);
            search_URD(board,'X','O',c,k);
            search_URD(board,'X','O',c,k);
            search_ULD(board,'X','O',c,k);
            search_DLD(board,'X','O',c,k);
            search_DRD(board,'X','O',c,k);
            return 1;
        }
        else
            return 0;
    }
    return 0;
}

int C_search_URD(char board[][8],char a,char b,int i,int j)
{
    int m,n,k,l,count=0;
    for(m=i-1,n=j+1;m>=0,n<8;m--,n++)
    {
        if(board[m][n]==a)
            count=count+1;
        else if(board[m][n]==b && count>0)
        {
            for(k=m,l=n;k<i,l>j;k++,l--)
                board[k][l]='X';
            search_left_HR(board,'X','O',m,n);
            search_VD(board,'X','O',m,n);
            search_VU(board,'X','O',m,n);
            search_right_HR(board,'X','O',m,n);
            search_URD(board,'X','O',m,n);
            search_ULD(board,'X','O',m,n);
            search_DLD(board,'X','O',m,n);
            search_DRD(board,'X','O',m,n);
            return 1;
        }
        else
            return 0;
    }
    return 0;
}

int C_search_ULD(char board[][8],char a,char b,int i,int j)
{
    int m,n,k,l,count=0;
    for(m=i-1,n=j-1;m>=0,n>=0;m--,n--)
    {
        if(board[m][n]==a)
            count=count+1;
        else if(board[m][n]==b && count>0)
        {
            for(k=m,l=n;k<i,l<j;k++,l++)
                board[k][l]='X';
            search_left_HR(board,'X','O',m,n);
            search_VD(board,'X','O',m,n);
            search_VU(board,'X','O',m,n);
            search_URD(board,'X','O',m,n);
            search_URD(board,'X','O',m,n);
            search_right_HR(board,'X','O',m,n);
            search_DLD(board,'X','O',m,n);
            search_DRD(board,'X','O',m,n);
            return 1;
        }
        else
            return 0;
    }
    return 0;
}

int C_search_DLD(char board[][8],char a,char b,int i,int j)
{
    int m,n,k,l,count=0;
    for(m=i+1,n=j-1;m<8,n>=0;m++,n--)
    {
        if(board[m][n]==a)
            count=count+1;
        else if(board[m][n]==b && count>0)
        {
            for(k=m,l=n;k>i,l<j;k--,l++)
                board[k][l]='X';
            search_left_HR(board,'X','O',m,n);
            search_VD(board,'X','O',m,n);
            search_VU(board,'X','O',m,n);
            search_URD(board,'X','O',m,n);
            search_URD(board,'X','O',m,n);
            search_ULD(board,'X','O',m,n);
            search_right_HR(board,'X','O',m,n);
            search_DRD(board,'X','O',m,n);
            return 1;
        }
        else
            return 0;
    }
    return 0;
}

int C_search_DRD(char board[][8],char a,char b,int i,int j)
{
    int m,n,k,l,count=0;
    for(m=i+1,n=j+1;m<8,n<8;m++,n++)
    {
        if(board[m][n]==a)
            count=count+1;
        else if(board[m][n]==b && count>0)
        {
            for(k=m,l=n;k>i,l>j;k--,l--)
                board[k][l]='X';
            search_left_HR(board,'X','O',m,n);
            search_VD(board,'X','O',m,n);
            search_VU(board,'X','O',m,n);
            search_URD(board,'X','O',m,n);
            search_URD(board,'X','O',m,n);
            search_ULD(board,'X','O',m,n);
            search_DLD(board,'X','O',m,n);
            search_right_HR(board,'X','O',m,n);
            return 1;
        }
        else
            return 0;
    }
    return 0;
}

void winner(char board[][8])
{
    int i,j,count=0;
    for(i=0;i<8;i++)
    {
        for(j=0;j<8;j++)
        {
            if(board[i][j]=='X')
                count++;
        }
    }
    if(count>=32)
        cout<<"\n*****Sorry You lost!! Try again someday****";
    else
        cout<<"\n****Congratulations!!! You have WON*****";
}

