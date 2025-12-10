// small note: testing main setup

#include <iostream>
#include "Detector.h"
#include "Alarm.h"
#include "Light.h"
#include "LogObserver.h"

using namespace std;

int main() {
    Detector detector;

    Alarm alarm;
    Light light;
    LogObserver logger;

    detector.attach(&alarm);
    detector.attach(&light);
    detector.attach(&logger);

    int choice;

    while (true) {

        cout << "\n-------------------------------\n";
        cout << "\n--- Starting new cycle ---\n";
        cout << "\n=== Smart Home Detection System ===\n";
        cout << "Press 1 to simulate Danger.\n";
        cout << "Press 0 to Exit.\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
        cout << "[System] Danger signal received...\n";
            detector.setDanger(true);
        } else if (choice == 0) {
            break;
        } else {
            cout << "Invalid choice!\n";
        }
    }

    return 0;
}
