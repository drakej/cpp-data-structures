#include <iostream>
#include <iomanip>

using namespace std;

#include "Stack.h"

void displayTowers(Stack &tower1, Stack &tower2, Stack &tower3)
{
    cout << "Tower 1";
    cout << std::setw(28) << "Tower 2";
    cout << std::setw(28) << "Tower 3" << endl;

    tower1.display(cout, 0);

    tower2.display(cout, 30);

    tower3.display(cout, 60);

    cout << endl
         << endl;
}

int main()
{
    int numRings;
    cout << "How many rings do you want? ";
    cin >> numRings;
    string rings[numRings];
    Stack tower1, tower2, tower3;
    string topRingTower1, topRingTower2, topRingTower3;

    for (int i = numRings; i > 0; i--)
    {
        rings[i - 1] = "(" + std::string(i, ' ') + ")";
        tower1.push(rings[i - 1]);
    }

    displayTowers(tower1, tower2, tower3);

    while (tower2.size() != numRings and tower3.size() != numRings)
    {
        topRingTower1 = tower1.top();
        topRingTower2 = tower2.top();

        if (!tower1.empty() && (tower2.empty() || topRingTower1.length() < topRingTower2.length()))
        {
            tower2.push(tower1.pop());
        }
        else if (!tower2.empty() && (tower1.empty() || topRingTower1.length() > topRingTower2.length()))
        {
            tower1.push(tower2.pop());
        }

        topRingTower1 = tower1.top();
        topRingTower3 = tower3.top();

        if (!tower1.empty() && (tower3.empty() || topRingTower1.length() < topRingTower3.length()))
        {
            tower3.push(tower1.pop());
        }
        else if (!tower3.empty() && (tower1.empty() || topRingTower1.length() > topRingTower3.length()))
        {
            tower1.push(tower3.pop());
        }

        topRingTower2 = tower2.top();
        topRingTower3 = tower3.top();

        if (!tower2.empty() && (tower3.empty() || topRingTower2.length() < topRingTower3.length()))
        {
            tower3.push(tower2.pop());
        }
        else if (!tower3.empty() && (tower2.empty() || topRingTower2.length() > topRingTower3.length()))
        {
            tower2.push(tower3.pop());
        }

        displayTowers(tower1, tower2, tower3);
    }
}
