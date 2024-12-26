//Insertion Sort

#include <iostream>
#include <vector>

struct Transaction {
    int id;
    double amount;
    int frequency;
    double score;
};

// Function to calculate score based on amount and frequency
double calculateScore(double amount, int frequency) {
    return 0.5 * amount + 0.3 * frequency;
}

// Insertion Sort to sort transactions by score
void insertionSort(std::vector<Transaction>& transactions) {
    int n = transactions.size();
    for (int i = 1; i < n; i++) {
        Transaction key = transactions[i];
        int j = i - 1;

        // Move elements of transactions[0..i-1] that are greater than key.score
        // to one position ahead of their current position
        while (j >= 0 && transactions[j].score < key.score) {
            transactions[j + 1] = transactions[j];
            j = j - 1;
        }
        transactions[j + 1] = key;
    }
}

int main() {
    // Sample transactions
    std::vector<Transaction> transactions = {
        {101, 5000.0, 5, 0.0},
        {102, 200.0, 10, 0.0},
        {103, 15000.0, 2, 0.0},
        {104, 800.0, 20, 0.0},
        {105, 10000.0, 15, 0.0}
    };

    // Calculate score for each transaction
    for (auto& tx : transactions) {
        tx.score = calculateScore(tx.amount, tx.frequency);
    }

    // Sort transactions by score using Insertion Sort
    insertionSort(transactions);

    // Display flagged transactions with score >= 5000
    std::cout << "Flagged Transactions (Score >= 5000):\n";
    for (const auto& tx : transactions) {
        if (tx.score >= 5000) {
            std::cout << "ID: " << tx.id << ", Score: " << tx.score << ", Amount: " << tx.amount << "\n";
        }
    }

    return 0;
}