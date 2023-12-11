#include <iostream>
#include <algorithm> // for std::swap
using namespace std;

// Define the Student structure before using it
struct Student {
    int rollno;
    string name; // Change name from string array to string
    float sgpa;
};

// Function prototypes
void input(Student& s);
void displayStudentList(Student s[], int n);
void bubbleSort(Student arr[], int n);
void quickSort(Student arr[], int low, int high);
int partition(Student arr[], int low, int high);

int main() {
    int n;
    cout << "Enter the number of students:" << endl;
    cin >> n;

    Student s[n];
    for (int i = 0; i < n; i++) {
        input(s[i]); // Pass each student to the input function
    }

    bubbleSort(s, n);
    cout << "\nRoll Call List (Sorted by Roll Numbers):\n";
    displayStudentList(s, n);

    quickSort(s, 0, n - 1);
    cout << "\nTop Ten Toppers:\n";
    displayStudentList(s, min(10, n));

    return 0;
}

// Function to input student details
void input(Student& s) {
    cout << "Enter student name:" << endl;
    cin >> s.name; // Removed extra `>>endl`

    cout << "Enter student rollno.:" << endl;
    cin >> s.rollno;

    cout << "Enter student SGPA:" << endl;
    cin >> s.sgpa;
}

// Function to display a list of students
void displayStudentList(Student s[], int n) {
    cout << "Roll No\tName\tSGPA\n";
    for (int i = 0; i < n; i++) {
        cout << s[i].rollno << "\t" << s[i].name << "\t" << s[i].sgpa << "\n";
    }
}

// Function to perform Bubble Sort on the student records based on roll numbers
void bubbleSort(Student arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j].rollno > arr[j + 1].rollno) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// Function to perform Quick Sort on the student records based on SGPA
void quickSort(Student arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Function to partition the array for Quick Sort
int partition(Student arr[], int low, int high) {
    float pivot = arr[high].sgpa;
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j].sgpa >= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return i + 1;
}
