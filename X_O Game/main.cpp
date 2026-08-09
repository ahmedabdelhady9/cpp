#include <iostream>

using namespace std;
char arr[3][3]= {{'1','2','3'},{'4','5','6'},{'7','8','9'}};
char position;
char player='x';
int xCounter=0;
int oCounter=0;
void show()
{
    cout<<"\n\n\t\t\t___________________"<<endl;
    cout<<"\t\t\t|     |     |     |"<<endl;
    cout<<"\t\t\t|  "<<arr[0][0]<<"  |  "<<arr[0][1]<<"  |  "<<arr[0][2]<<"  |"<<endl;
    cout<<"\t\t\t|_____|_____|_____|"<<endl;
    cout<<"\t\t\t|     |     |     |"<<endl;
    cout<<"\t\t\t|  "<<arr[1][0]<<"  |  "<<arr[1][1]<<"  |  "<<arr[1][2]<<"  |"<<endl;
    cout<<"\t\t\t|_____|_____|_____|"<<endl;
    cout<<"\t\t\t|     |     |     |"<<endl;
    cout<<"\t\t\t|  "<<arr[2][0]<<"  |  "<<arr[2][1]<<"  |  "<<arr[2][2]<<"  |"<<endl;
    cout<<"\t\t\t|_____|_____|_____|"<<endl;
}
void play()
{
    cout<<"please Enter Position From(1-9) For Player : "<<player<<endl;
    cin>>position;
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            if(arr[i][j]==position)
            {
                arr[i][j]=player;
                break;
            }
        }
    }
    if(player=='x')
    {
        player='o';
    }
    else
    {
        player='x';
    }
}
char winner()
{
    int test=0;
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            if(arr[i][j]!='x'&&arr[i][j]!='o')
            {
                test=1;
            }
            if(arr[i][j]=='x')
            {
                xCounter++;
            }
            else if(arr[i][j]=='o')
            {
                oCounter++;
            }
        }
        if(xCounter==3)
        {
            return 'x';
        }
        else if(oCounter==3)
        {
            return 'o';
        }
        xCounter=oCounter=0;
    }
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            if(arr[i][j]!='x'&&arr[i][j]!='o')
            {
                test=1;
            }
            if(arr[j][i]=='x')
            {
                xCounter++;
            }
            else if(arr[j][i]=='o')
            {
                oCounter++;
            }
        }
        if(xCounter==3)
        {
            return 'x';
        }
        else if(oCounter==3)
        {
            return 'o';
        }
        xCounter=oCounter=0;
    }
    if(arr[0][0]=='x'&&arr[1][1]=='x'&&arr[2][2]=='x')
    {
        return 'x';
    }
    else if(arr[0][0]=='o'&&arr[1][1]=='o'&&arr[2][2]=='o')
    {
        return 'o';
    }
    else if(arr[0][2]=='x'&&arr[1][1]=='x'&&arr[2][0]=='x')
    {
        return 'x';
    }
    else if(arr[0][2]=='o'&&arr[1][1]=='o'&&arr[2][0]=='o')
    {
        return 'o';
    }
    if(test==0)
    {
        return 'z';
    }
    return '.';
}
int main()
{
    while(winner()=='.')
    {
        show();
        play();
        system("cls");
    }
    show();
    if(winner()=='z')
    {
        cout<<"No Winner In This Game!!"<<endl;
    }
    else
    {
        cout<<"The Winner In This Game Is Player : "<<winner()<<" Congratulations"<<endl;
    }

}
