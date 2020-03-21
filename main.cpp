

#include <iostream>
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
int main()
{
    int i,j,x,y,count,flag=0,temp=0,a1,a2,a3,a4,a5,a6,a7,a8;
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
    /*board[3][3] = 'X';
    board[3][4] = 'X';
    board[3][5] = 'X';
    board[4][3] = 'X';
    board[4][5] = 'X';
    board[5][3] = 'X';
    board[5][4] = 'X';
    board[5][5] = 'X';
    board[2][2] = 'O';
    board[2][4] = 'O';
    board[2][6] = 'O';
    board[4][2] = 'O';
    board[4][6] = 'O';
    board[6][2] = 'O';
    board[6][4] = 'O';
    board[6][6] = 'O';*/
    while(1)
    {
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
        cout<<"Computer's Turn....!";
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
        
                
        
    }
}

//Function to take X-coordinate from user
int user_insertion_X()
{
    int x;
    cout<<"Enter the X-cordinate of your insertion: ";
    cin>>x;
    return x;
}

//Function to take Y-coordinate from user
int user_insertion_Y()
{
    int y;
    cout<<"Enter the Y-cordinate of your insertion: ";
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
    for(m=i-1,n=j+1;static_cast<void>(m>=0),n<8;m--,n++)
    {
        if(board[m][n]==b)
            count=count+1;
        else if(board[m][n]==a && count>0)
        {
            for(k=m,l=n;static_cast<void>(k<i),l>j;k++,l--)
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
    for(m=i+1,n=j+1;static_cast<void>(m<8),n<8;m++,n++)
    {
        if(board[m][n]==b)
            count=count+1;
        else if(board[m][n]==a && count>0)
        {
            for(k=m,l=n;static_cast<void>(k>i),l>j;k--,l--)
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
    for(m=i+1,n=j-1;static_cast<void>(m<8),n>=0;m++,n--)
    {
        if(board[m][n]==b)
            count=count+1;
        else if(board[m][n]==a && count>0)
        {
            for(k=m,l=n;static_cast<void>(k>i),l<j;k--,l++)
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
    for(m=i-1,n=j-1;static_cast<void>(m>=0),n>=0;m--,n--)
    {
        if(board[m][n]==b)
            count=count+1;
        else if(board[m][n]==a && count>0)
        {
            for(k=m,l=n;static_cast<void>(k<i),l<j;k++,l++)
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
    for(i=0;i<8;i++)
    {
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
    for(m=i-1,n=j+1;static_cast<void>(m>=0),n<8;m--,n++)
    {
        if(board[m][n]==a)
            count=count+1;
        else if(board[m][n]==b && count>0)
        {
            for(k=m,l=n;static_cast<void>(k<i),l>j;k++,l--)
                board[k][l]='X';
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
    for(m=i-1,n=j-1;static_cast<void>(m>=0),n>=0;m--,n--)
    {
        if(board[m][n]==a)
            count=count+1;
        else if(board[m][n]==b && count>0)
        {
            for(k=m,l=n;static_cast<void>(k<i),l<j;k++,l++)
                board[k][l]='X';
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
    for(m=i+1,n=j-1;static_cast<void>(m<8),n>=0;m++,n--)
    {
        if(board[m][n]==a)
            count=count+1;
        else if(board[m][n]==b && count>0)
        {
            for(k=m,l=n;static_cast<void>(k>i),l<j;k--,l++)
                board[k][l]='X';
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
    for(m=i+1,n=j+1;static_cast<void>(m<8),n<8;m++,n++)
    {
        if(board[m][n]==a)
            count=count+1;
        else if(board[m][n]==b && count>0)
        {
            for(k=m,l=n;static_cast<void>(k>i),l>j;k--,l--)
                board[k][l]='X';
            return 1;
        }
        else
            return 0;
    }
    return 0;
}
