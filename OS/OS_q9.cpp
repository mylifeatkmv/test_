#include<iostream>
using namespace std;

int main() {
    int a[10], b[10], x[10];
    int waiting[10], turnaround[10], completion[10];
    int i, j, count = 0, n;
    double avg = 0, tt = 0, end;

    cout << "\nEnter the number of Processes: ";
    cin >> n;

    cout << "\nEnter arrival time of process:\n";
    for (i = 0; i < n; i++) {
        cout << "P[" << i + 1 << "]: ";
        cin >> a[i];
    }

    cout << "\nEnter burst time of process:\n";
    for (i = 0; i < n; i++) {
        cout << "P[" << i + 1 << "]: ";
        cin >> b[i];
        x[i] = b[i];
    }

    for (i = 0; i < n; i++) {
        if (i == 0) {
            completion[i] = a[i] + b[i];
        } else {
            completion[i] = completion[i - 1] + b[i];
        }

        turnaround[i] = completion[i] - a[i];
        waiting[i] = turnaround[i] - b[i];

        avg += waiting[i];
        tt += turnaround[i];
    }

    cout << "Process\tBurst-time\tArrival-time\tWaiting-time\tTurnaround-time\tCompletion-time" << endl;

    for (i = 0; i < n; i++) {
        cout << "p" << i + 1 << "\t\t" << x[i] << "\t\t" << a[i] << "\t\t" << waiting[i] << "\t\t"
             << turnaround[i] << "\t\t" << completion[i] << endl;
    }

    cout << "\nAverage waiting time = " << avg / n;
    cout << "\nAverage Turnaround time = " << tt / n << endl;

    return 0;
}
