#include <iostream>
using namespace std;

void setPotion(int count, int* p_HPPotion, int* p_MPPotion) {
    *p_HPPotion = count;
    *p_MPPotion = count;
}

int main() {

    const int SIZE = 4;
    int stat[SIZE] = { 0 };

    while (1) {
        cout << "Please enter HP and MP: ";
        cin >> stat[0] >> stat[1];

        if (stat[0] > 50 && stat[1] > 50) {
            break;
        }
        cout << "HP or MP value is too low. Please enter again." << endl;
    }

    while (1) {
        cout << "Please enter Attack and Defense: ";
        cin >> stat[2] >> stat[3];

        if (stat[2] > 0 && stat[3] > 0) {
            break;
        }
        cout << "Attack or Defense value is too low. Please enter again." << endl;
    }

    int choice = 0;
    int HPPotion = 0;
    int MPPotion = 0;

    setPotion(5, &HPPotion, &MPPotion);

    cout << "* Potions have been granted. (5 HP potions and 5 MP potions)" << endl;
    cout << "=============================================" << endl;
    cout << "<Stat Management System>" << endl;

    while (1) {
        cout << "1.HP / 2.MP / 3.ATK / 4.DEF / 5.STATUS / 0.EXIT" << endl;
        cout << "Please select a number: ";
        cin >> choice;

        if (choice == 0) {
            cout << "Program terminated." << endl;
            break;
        }

        switch (choice) {
        case 1:
            if (HPPotion <= 0) {
                cout << "Not enough potions." << endl;
                continue;
            }
            stat[0] += 20;
            HPPotion--;
            cout << "* HP increased by 20. 1 potion consumed." << endl;
            cout << "Current HP: " << stat[0] << endl;
            cout << "Remaining potions: " << HPPotion << endl;
            break;

        case 2:
            if (MPPotion <= 0) {
                cout << "Not enough potions." << endl;
                continue;
            }
            stat[1] += 20;
            MPPotion--;
            cout << "* MP increased by 20. 1 potion consumed." << endl;
            cout << "Current MP: " << stat[1] << endl;
            cout << "Remaining potions: " << MPPotion << endl;
            break;

        case 3:
            stat[2] *= 2;
            cout << "* Attack has doubled." << endl;
            cout << "Current Attack: " << stat[2] << endl;
            break;

        case 4:
            stat[3] *= 2;
            cout << "* Defense has doubled." << endl;
            cout << "Current Defense: " << stat[3] << endl;
            break;

        case 5:
            cout << "HP: " << stat[0]
                << " MP: " << stat[1]
                << " Attack: " << stat[2]
                << " Defense: " << stat[3] << endl;
            break;

        default:
            cout << "Please enter a valid number." << endl;
            break;
        }
    }
    return 0;
}