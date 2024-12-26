//Bubble Sort

#include <iostream>
#include <vector>

struct Patient {
    std::string name;       // Patient's name
    int triagePriority;     // Triage priority (1: highest, 5: lowest)
    int severity;           // Severity of condition (higher is worse)
    int arrivalTime;        // Arrival time (earlier is prioritized)
};

// Bubble Sort function to sort the patients
void bubbleSort(std::vector<Patient>& patients) {
    int n = patients.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            // Compare based on triage priority, severity, and arrival time
            if (patients[j].triagePriority > patients[j + 1].triagePriority ||
                (patients[j].triagePriority == patients[j + 1].triagePriority && patients[j].severity < patients[j + 1].severity) ||
                (patients[j].triagePriority == patients[j + 1].triagePriority && patients[j].severity == patients[j + 1].severity && patients[j].arrivalTime > patients[j + 1].arrivalTime)) {
                
                // Swap if needed
                std::swap(patients[j], patients[j + 1]);
            }
        }
    }
}

int main() {
    // Sample list of patients
    std::vector<Patient> patients = {
        {"Alice", 3, 70, 5},
        {"Bob", 1, 90, 2},
        {"Charlie", 2, 80, 3},
        {"Diana", 1, 95, 1},
        {"Eve", 4, 60, 4}
    };

    // Sort patients using Bubble Sort
    bubbleSort(patients);

    // Display sorted patient list
    std::cout << "Sorted Patients List:\n";
    for (const auto& patient : patients) {
        std::cout << "Name: " << patient.name 
                  << ", Priority: " << patient.triagePriority 
                  << ", Severity: " << patient.severity 
                  << ", Arrival Time: " << patient.arrivalTime << "\n";
    }

    return 0;
}