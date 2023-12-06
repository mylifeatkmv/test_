#include<iostream>
#include<algorithm>
using namespace std;

struct Process {
    int id;
    int priority;
    int burstTime;
    int arrivalTime;
    int waitingTime;
    int turnaroundTime;
    int completionTime;
};

bool compare(Process a, Process b) {
    return (a.priority < b.priority);
}

int main() {
    int n;
    cout << "\nEnter the number of Processes: ";
    cin >> n;

    Process processes[n];

    cout << "\nEnter arrival time, burst time, and priority of each process:\n";
    for (int i = 0; i < n; i++) {
        processes[i].id = i + 1;
        cout << "P[" << i + 1 << "]: ";
        cin >> processes[i].arrivalTime >> processes[i].burstTime >> processes[i].priority;
    }

    sort(processes, processes + n, compare);

    int currentTime = 0;
    for (int i = 0; i < n; i++) {
        if (currentTime < processes[i].arrivalTime) {
            currentTime = processes[i].arrivalTime;
        }

        processes[i].waitingTime = currentTime - processes[i].arrivalTime;
        processes[i].turnaroundTime = processes[i].waitingTime + processes[i].burstTime;
        processes[i].completionTime = currentTime + processes[i].burstTime;

        currentTime = processes[i].completionTime;
    }

    double avgWaitingTime = 0, avgTurnaroundTime = 0;

    cout << "\nProcess\tArrival Time\tBurst Time\tPriority\tWaiting Time\tTurnaround Time\tCompletion Time\n";
    for (int i = 0; i < n; i++) {
        cout << "P[" << processes[i].id << "]\t" << processes[i].arrivalTime << "\t\t"
             << processes[i].burstTime << "\t\t" << processes[i].priority << "\t\t"
             << processes[i].waitingTime << "\t\t" << processes[i].turnaroundTime << "\t\t"
             << processes[i].completionTime << endl;

        avgWaitingTime += processes[i].waitingTime;
        avgTurnaroundTime += processes[i].turnaroundTime;
    }

    avgWaitingTime /= n;
    avgTurnaroundTime /= n;

    cout << "\nAverage Waiting Time: " << avgWaitingTime;
    cout << "\nAverage Turnaround Time: " << avgTurnaroundTime << endl;

    return 0;
}
