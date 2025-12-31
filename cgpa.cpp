#include <bits/stdc++.h>

using namespace std;

float getGradePoints(float marks)
{
    if (marks >= 85)
        return 5.0;
    else if (marks >= 75)
        return 4.5;
    else if (marks >= 65)
        return 4.0;
    else if (marks >= 55)
        return 3.5;
    else if (marks >= 45)
        return 3.0;
    else if (marks >= 40)
        return 2.5;
    else
        return 0.0;
}

float gpa_calculator()
{
    int no_of_subjects;
    float totalPoints = 0.0;
    int totalCredits = 0;
    cout << "Enter number of subjects/modules:";
    cin >> no_of_subjects;

    if (no_of_subjects <= 0)
    {
        cout << "Invalid number of subjects/modules" << endl;
        return -1;
    }

    string courseNames[no_of_subjects];
    float marks[no_of_subjects];
    int credits[no_of_subjects];
    float gradePoints[no_of_subjects];

    for (int i = 0; i < no_of_subjects; i++)
    {
        cout << "Enter name of subject/module " << i + 1 << ": ";
        cin >> courseNames[i];
        cout << "Enter marks obtained in " << courseNames[i] << ": ";
        cin >> marks[i];

        if (marks[i] < 0 || marks[i] > 100)
        {
            cout << "Invalid marks entered." << endl;
            return -1;
        }

        cout << "Enter credits for " << courseNames[i] << ": ";
        cin >> credits[i];

        if (credits[i] <= 0)
        {
            cout << "Invalid credits entered." << endl;
            return -1;
        }

        gradePoints[i] = getGradePoints(marks[i]);
        totalPoints += gradePoints[i] * credits[i];
        totalCredits += credits[i];
    }
    float gpa = totalPoints / totalCredits;
    cout << "GPA is calculated successfully." << endl;
    cout << "GPA : " << gpa << endl;
    return gpa;
}

int cgpa_calculator()
{

    int no_of_semesters;
    cout << "Enter number of semesters: ";
    cin >> no_of_semesters;
    if (no_of_semesters <= 0)
    {
        cout << "invalid number of semesters entered." << endl;
        return -1;
    }
    float total_points = 0.0;
    int total_credits = 0;
    int credits;
    float gpas[no_of_semesters];

    for (int i = 0; i < no_of_semesters; i++)
    {
        cout << "Enter GPA for semester " << i + 1 << ": ";
        cin >> gpas[i];
        if (gpas[i] < 0.0 || gpas[i] > 5.0)
        {
            cout << "invalid GPA entered." << endl;
            return -1;
        }
        cout << "Enter total credits for semester " << i + 1 << ": ";
        cin >> credits;

        total_points += gpas[i] * credits;
        total_credits += credits;
    }
    float cgpa = total_points / total_credits;
    cout << "CGPA is calculated successfully." << endl;
    cout << "CGPA : " << cgpa << endl;
    return cgpa;
}

int main()
{
    int choice;
    cout << "1. Gpa calculator\n2. Cgpa calculator\n3. Exit\n";
    cin >> choice;
    switch (choice)
    {
    case 1:
        gpa_calculator();
        break;

    case 2:
        cgpa_calculator();
        break;

    case 3:
        exit(0);
        break;
    }

    return 0;
}