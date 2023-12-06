
#include<iostream>
#include<algorithm>
using namespace std;

#define max 25

struct Process {
    int id;
    int size;
    int blockNumber;
    int blockSize;
    int fragment;
};

bool compare(Process a, Process b) {
    return (a.size < b.size);
}

void firstFit(int nb, int nf, int b[], int f[]) {
    int frag[max], bf[max], ff[max];

    for (int i = 1; i <= nf; i++) {
        int temp = -1;
        for (int j = 1; j <= nb; j++) {
            if (bf[j] != 1) {
                temp = b[j] - f[i];
                if (temp >= 0) {
                    ff[i] = j;
                    break;
                }
            }
        }
        frag[i] = temp;
        bf[ff[i]] = 1;
    }

    cout << "\nFile No\tFile Size \tBlock No.\tBlock Size\tFragment" << endl;
    for (int i = 1; i <= nf; i++) {
        cout << i << "\t\t" << f[i] << "\t\t" << ff[i] << "\t\t" << b[ff[i]] << "\t\t" << frag[i] << endl;
    }
}

void bestFit(int nb, int nf, int b[], int f[]) {
    int frag[max], bf[max], ff[max];

    for (int i = 1; i <= nf; i++) {
        int bestFit = -1;
        for (int j = 1; j <= nb; j++) {
            if (bf[j] != 1) {
                int temp = b[j] - f[i];
                if (temp >= 0) {
                    if (bestFit == -1 || b[j] < b[bestFit]) {
                        bestFit = j;
                    }
                }
            }
        }

        if (bestFit != -1) {
            ff[i] = bestFit;
            frag[i] = b[bestFit] - f[i];
            bf[ff[i]] = 1;
        }
    }

    cout << "\nFile No\tFile Size \tBlock No.\tBlock Size\tFragment" << endl;
    for (int i = 1; i <= nf; i++) {
        cout << i << "\t\t" << f[i] << "\t\t" << ff[i] << "\t\t" << b[ff[i]] << "\t\t" << frag[i] << endl;
    }
}

void worstFit(int nb, int nf, int b[], int f[]) {
    int frag[max], bf[max], ff[max];

    for (int i = 1; i <= nf; i++) {
        int worstFit = -1;
        for (int j = 1; j <= nb; j++) {
            if (bf[j] != 1) {
                int temp = b[j] - f[i];
                if (temp >= 0) {
                    if (worstFit == -1 || b[j] > b[worstFit]) {
                        worstFit = j;
                    }
                }
            }
        }

        if (worstFit != -1) {
            ff[i] = worstFit;
            frag[i] = b[worstFit] - f[i];
            bf[ff[i]] = 1;
        }
    }

    cout << "\nFile No\tFile Size \tBlock No.\tBlock Size\tFragment" << endl;
    for (int i = 1; i <= nf; i++) {
        cout << i << "\t\t" << f[i] << "\t\t" << ff[i] << "\t\t" << b[ff[i]] << "\t\t" << frag[i] << endl;
    }
}

int main() {
    int nb, nf;

    cout << "\n\tMemory Management Scheme - Menu\n";
    cout << "1. First Fit\n";
    cout << "2. Best Fit\n";
    cout << "3. Worst Fit\n";
    cout << "Choose memory allocation strategy (1/2/3): ";
    int choice;
    cin >> choice;

    cout << "Enter the number of blocks: ";
    cin >> nb;
    cout << "Enter the number of files: ";
    cin >> nf;

    int b[max], f[max];

    cout << "\nEnter the size of the blocks:\n";
    for (int i = 1; i <= nb; i++) {
        cout << "Block " << i << ": ";
        cin >> b[i];
    }

    cout << "Enter the size of the files:\n";
    for (int i = 1; i <= nf; i++) {
        cout << "File " << i << ": ";
        cin >> f[i];
    }

    switch (choice) {
        case 1:
            firstFit(nb, nf, b, f);
            break;
        case 2:
            bestFit(nb, nf, b, f);
            break;
        case 3:
            worstFit(nb, nf, b, f);
            break;
        default:
            cout << "Invalid choice\n";
    }

    return 0;
}
