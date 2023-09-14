#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void guessingnumber(int data)
{
    int value = data;
    cout << "Try to guess the number" << endl;
    cout << "guess a number between 1 to 100" << endl;

    for (int i = 1; i < 15; i++)
    {
        int num; 
        cout << "chance" << i << " : " << endl;
        cin >> num;

        // if the guessed number is lower than the generated number, code is here
        if (value - num > 50)
        {

            cout << " u guessed a number that is  too  low" << endl;
        }

        else if (value - num > 25)
        {

            cout << " u gussed the number that is low " << endl;
        }

        else if (value - num > 10)
        {

            cout << " u gussed the number that little low " << endl;
        }
        else if (value - num > 5)
        {
            cout << " u gussed the number that is near,select a Higher number " << endl;
        }
        else if (value - num > 0)
        {
            cout << " u gussed the number that is near,select a higher number " << endl;
        }

        // if the guessed number is higher than generated number ,code is here
        else if (num - value > 50)
        {
            cout << " u gussed the number that is too high " << endl;
        }

        else if (num - value > 25)
        {
            cout << " u gussed the number that is high " << endl;
        }

        else if (num - value > 10)
        {
            cout << " u gussed the number that little high" << endl;
        }

        else if (num - value > 5)
        {
            cout << " u gussed the number that is near ,select a slight Lower number " << endl;
        }

        else if (num - value > 0)
        {
            cout << " u gussed the number that is near ,select a slight lower number " << endl;
        }
        // condition when guessed number matched with generated number
        else
        {
            // cout<<value<<endl;
            cout << "congratulations u did a great job" << endl;
            break;
        }
    }
}

int main()
{
    srand(time(0));
    guessingnumber(rand() % 100);
    return 0;
}