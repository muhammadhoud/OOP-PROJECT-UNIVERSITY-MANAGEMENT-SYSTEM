//TO FIRST TIME RUN THE PROGRAM TO TEST:
//
//FOR STUDENT:-
//USERNAME: GORDON123
//PASSWORD: JLJIJJIJJ345
//
//FOR TEACHER:-
//USERNAME: HAPO1234
//PASSWORD: PASS1234
//
//FOR ADMIN:-
//USERNAME: Admin
//PASSWORD: Admin123

#include "Database.hpp"

int main()
{
    char i = 'y';
    while (i != 27)
    {
        system("cls");
        system("Color F1");
        cout << endl << endl << "\t\tFLEX MANAGEMENT SYSTEM" << endl;
        cout << endl << "1.    PRESS 1 TO LOGIN AS ADMIN" << endl;
        cout << "2.    PRESS 2 TO LOGIN AS TEACHER" << endl;
        cout << "3.    PRESS 3 TO LOGIN AS STUDENT" << endl;
        cout << "5.    PRESS Esc TO END PROGRAM" << endl;
        i = _getch();
        if (i == '1')
        {
            Admin aobj;
            aobj.signin();
        }
        else if (i == '2')
        {
            Teacher tobj;
            tobj.signin();
        }
        else if (i == '3')
        {
            Student sobj;
            sobj.sign_in_student();
        }
        else if (i != 27)
        {
            system("cls");
            cout << endl << "PLEASE PRESS A VALID NUMBER" << endl;
        }
    }
    return 0;
}
