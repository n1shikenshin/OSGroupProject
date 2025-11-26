#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

int main() {
    int initialPos, n;
    string direction;
    vector<int> requests;

    // Input Section
    cout << "Enter initial arm position (0-199): ";
    cin >> initialPos;

    cout << "Enter direction (UP/DOWN): ";
    cin >> direction;
    transform(direction.begin(), direction.end(), direction.begin(), ::toupper);

    cout << "Enter number of track requests: ";
    cin >> n;

    cout << "Enter track requests: ";
    for (int i = 0; i < n; i++) {
        int track;
        cin >> track;
        requests.push_back(track);
    }

    // Sort requests
    sort(requests.begin(), requests.end());

    cout << "\nSorted requests: ";
    for (int req : requests) cout << req << " ";
    cout << "\n\n";

    cout << "=========================================\n";
    cout << "Initial Arm position: " << initialPos 
         << "\tDirection: " << direction << "\n";
    cout << "=========================================\n\n";

    cout << left << setw(10) << "Start" 
         << setw(15) << "Finished" 
         << "Track Travelled\n";
    cout << "-------------------------------------------\n";

    int currentPos = initialPos;
    int totalTrackTravelled = 0;
    vector<int> serviceOrder;

    // ----------------- UP DIRECTION -----------------
    if (direction == "UP") {

        // Step 1: Serve requests >= current head
        for (int req : requests) {
            if (req >= currentPos) {
                int travel = abs(req - currentPos);
                cout << left << setw(10) << currentPos 
                     << setw(15) << req << travel << "\n";

                totalTrackTravelled += travel;
                currentPos = req;
                serviceOrder.push_back(req);
            }
        }

        // Step 2: Go to outermost track (199)
        if (currentPos != 199) {
            int travel = 199 - currentPos;
            cout << left << setw(10) << currentPos 
                 << setw(15) << 199 << travel << "\n";

            totalTrackTravelled += travel;
            currentPos = 199;
        }

        // Step 3: Wrap to 0 (counted in this assignment)
        int jumpDist = 199;
        cout << left << setw(10) << currentPos 
             << setw(15) << 0 << jumpDist << "\n";

        totalTrackTravelled += jumpDist;
        currentPos = 0;

        // Step 4: Serve remaining (< initialPos)
        for (int req : requests) {
            if (req < initialPos) {
                int travel = abs(req - currentPos);
                cout << left << setw(10) << currentPos 
                     << setw(15) << req << travel << "\n";

                totalTrackTravelled += travel;
                currentPos = req;
                serviceOrder.push_back(req);
            }
        }
    }

    // ----------------- DOWN DIRECTION -----------------
    else {

        // Step 1: Serve requests <= head (descending)
        for (int i = requests.size() - 1; i >= 0; i--) {
            if (requests[i] <= currentPos) {
                int travel = abs(currentPos - requests[i]);

                cout << left << setw(10) << currentPos 
                     << setw(15) << requests[i] << travel << "\n";

                totalTrackTravelled += travel;
                currentPos = requests[i];
                serviceOrder.push_back(requests[i]);
            }
        }

        // Step 2: Move to track 0
        if (currentPos != 0) {
            int travel = currentPos;

            cout << left << setw(10) << currentPos 
                 << setw(15) << 0 << travel << "\n";

            totalTrackTravelled += travel;
            currentPos = 0;
        }

        // Step 3: Wrap to 199
        int jumpDist = 199;
        cout << left << setw(10) << currentPos 
             << setw(15) << 199 << jumpDist << "\n";

        totalTrackTravelled += jumpDist;
        currentPos = 199;

        // Step 4: Serve requests greater than initialPos (descending)
        for (int i = requests.size() - 1; i >= 0; i--) {
            if (requests[i] > initialPos) {
                int travel = abs(currentPos - requests[i]);

                cout << left << setw(10) << currentPos 
                     << setw(15) << requests[i] << travel << "\n";

                totalTrackTravelled += travel;
                currentPos = requests[i];
                serviceOrder.push_back(requests[i]);
            }
        }
    }

    // Final output
    cout << "\nTotal Track Travelled: " << totalTrackTravelled << "\n\n";

    cout << "Service Order: ";
    for (int track : serviceOrder)
        cout << track << " ";
    cout << "\n";

    return 0;
}
