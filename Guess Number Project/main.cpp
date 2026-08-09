#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int level;
int secretNumber;
int guess;
int choices;
int won;

int main()
{
    srand(time(0));
    cout<<"Welcome to GuessTheNumber game!"<<endl;

    while(true)
    {
        cout<<"\nEnter the difficulty level:" << endl;
        cout<<"1 for easy!" << endl;
        cout<<"2 for medium!" << endl;
        cout<<"3 for difficult!" << endl;
        cout<<"0 for ending the game!" << endl;
        cin>>level;

        if(level==0)
        {
            cout<<"Thanks for playing!"<<endl;
            break;
        }

        if(level==1)
        {
            choices=10;
        }
        else if(level==2)
        {
            choices=7;
        }
        else if(level==3)
        {
            choices=5;
        }
        else
        {
            cout<<"Invalid level!"<<endl;
            continue;
        }

        secretNumber=rand()%100+1;
        cout<<"\nYou have "<<choices <<" choices for finding the secret number between 1 and 100."<< endl;
        won = 0;

        while(choices>0)
        {
            cout<<"\nEnter the number: ";
            cin>>guess;

            if(guess==secretNumber)
            {
                cout<<"Well played! You won, "<<guess<<" is the secret number."<<endl;
                won=1;
                break;
            }
            else if(guess<secretNumber)
            {
                cout<<"Nope, "<<guess<<" is not the right number."<<endl;
                cout<<"The secret number is greater than the number you have chosen."<<endl;

            }
            else
            {
                cout<<"Nope, "<<guess<<" is not the right number."<<endl;
                cout<<"The secret number is smaller than the number you have chosen."<<endl;
            }

            choices--;

            if(choices>0)
            {
                cout<<choices<<" choices left."<<endl;
            }
        }

        if(won==0)
        {
            cout<<"\nGame over!"<<endl;
            cout<<"The secret number was: "<<secretNumber<<endl;
        }

        cout<<"\nPlay the game again with us!"<<endl;
    }

    return 0;
}
