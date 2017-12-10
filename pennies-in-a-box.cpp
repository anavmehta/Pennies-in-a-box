/***************************************************************************
 *                                                                         *
 *   Copyright (C) 2017 by Anav Mehta                                      *
 *                                                                         *
 *   http://3dwaffles.blogspot.com                                         *
 *                                                                         *
 ***************************************************************************/
#include <iostream>
using namespace std;
#include <stdlib.h>
#include <time.h>



int main()
{
    int n;
    int a[100];
    n = -1;
    int player = 0;
    int scores[2];
    scores[0] = scores[1] = 0;
     srand (time(NULL));
    while(n <= 0) {
        cout << "Enter the size of the board" << endl;
        cin >> n;
    }
//    cout << "Enter " << n << " integers" << endl;
    int j = 0;
    while(j < n) {
        a[j] = rand() % 10000;
        j++;
    }
    int first;
    cout << "Should computer play first yes=0, no=1" << endl;
    cin >> first;
    while (first !=0 && first != 1) {
        cout << "Should computer play first yes=0 no=1" << endl;
        cin >> first;
    }
    bool firstmove = true;
    int computer = first;
    // find all
    int evens=0;
    int odds = 0;
    j = 0;
    while(j < n) {
        if( j %2 == 0) evens = evens + a[j];
        else odds = odds + a[j];
        j++;
    }
//    cout << "evens =" << evens << endl;
//    cout << "odds=" << odds << endl;
    bool chooseeven= false;
    if (evens > odds) chooseeven = true;
    j = 0;
    int start= 0;
    int finish = n;
    int k;
    int play;

    while (start < finish) {
        k = start;
        cout << "Board: ";
        while(k < finish) {
                    cout << a[k] << " ";
                    k++;

        }
        cout << endl;
        cout << "Computer is " << computer << " Player " << 0 << " score: " << scores[0] << " " << ", Player " << 1 << " score: " << scores[1] << endl;
        cout << endl;
        if(player != computer) {
            cout << "Player number " << player << " choose left (0) or right (1)" << endl;
            cin >> play;
            while(play != 0 && play != 1) {
                cout << "Player number " << player << " choose left (0) or right (0)" << endl;
                cin >> play;
            }
            if (play == 0) {
                scores[player] = scores[player] + a[start];
                cout << "Player " << player << " chose " << a[start] <<  endl;
                start++;
            } else {
                scores[player] = scores[player] + a[finish-1];
                cout << "Player " << player << " chose " << a[finish-1] << endl;
                finish--;
            }
        } else {
            if (start % 2 == (finish-1) %2 ) {
                if(a[start] > a[finish-1]) {
                    scores[player] = scores[player] + a[start];
                    cout << "Player " << player << " chose " << a[start] <<  endl;
                    start++;
                } else {
                    scores[player] = scores[player] + a[finish-1];
                    cout << "Player " << player << " chose " << a[finish-1] << endl;
                    finish--;
                }
            } else if((chooseeven && ((finish-1)%2 == 0)) || (!chooseeven && ((finish-1)%2 == 1))) {
                scores[player] = scores[player] + a[finish-1];
                cout << "Player " << player << " chose " << a[finish-1] << endl;
                finish--;
            } else if ((chooseeven && (start %2 == 0)) || (!chooseeven && (start %2 == 1))) {
                scores[player] = scores[player] + a[start];
                cout << "Player " << player << " chose " << a[start] <<  endl;
                start++;
            }
        }
        player = 1-player;

    }
    if(scores[0] > scores[1]) {
        cout << "Player 0 won" << endl;
    } else if(scores[1] > scores[0]) {
        cout << "Player 1 won" << endl;
    } else {
        cout << "Player 0 and Player 1 tied" << endl;
    }
    cout << "Final score. Player 0=" << scores[0] << " Player 1=" << scores[1] << endl;
}
