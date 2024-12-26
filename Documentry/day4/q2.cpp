//Merge Sort

#include <iostream>
#include <vector>
#include <string>

// Define the Trade structure
struct Trade {
    std::string timestamp;
    std::string symbol;
    double price;
    int volume;
};

// Merge function to merge two sorted halves of the vector
void merge(std::vector<Trade>& trades, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    
    // Temporary vectors for left and right halves
    std::vector<Trade> leftTrades(n1);
    std::vector<Trade> rightTrades(n2);

    // Copy data to temp vectors
    for (int i = 0; i < n1; i++)
        leftTrades[i] = trades[left + i];
    for (int i = 0; i < n2; i++)
        rightTrades[i] = trades[mid + 1 + i];

    // Merge the temp vectors back into the original vector
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (leftTrades[i].timestamp <= rightTrades[j].timestamp) {
            trades[k] = leftTrades[i];
            i++;
        } else {
            trades[k] = rightTrades[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of leftTrades[], if any
    while (i < n1) {
        trades[k] = leftTrades[i];
        i++;
        k++;
    }

    // Copy the remaining elements of rightTrades[], if any
    while (j < n2) {
        trades[k] = rightTrades[j];
        j++;
        k++;
    }
}

// Merge Sort function
void mergeSort(std::vector<Trade>& trades, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        // Recursively divide and merge
        mergeSort(trades, left, mid);
        mergeSort(trades, mid + 1, right);

        // Merge the sorted halves
        merge(trades, left, mid, right);
    }
}

int main() {
    // Sample trades
    std::vector<Trade> trades = {
        {"2024-12-24 09:00:01", "AAPL", 180.25, 100},
        {"2024-12-24 09:00:02", "GOOG", 2800.50, 200},
        {"2024-12-24 09:00:01", "MSFT", 350.75, 150},
        {"2024-12-24 09:00:03", "AAPL", 181.00, 300},
        {"2024-12-24 09:00:02", "MSFT", 351.00, 100}
    };

    // Apply Merge Sort to the trades vector
    mergeSort(trades, 0, trades.size() - 1);

    // Display sorted trades
    std::cout << "Trades sorted by Timestamp:\n";
    for (const auto& trade : trades) {
        std::cout << "Timestamp: " << trade.timestamp 
                  << ", Symbol: " << trade.symbol 
                  << ", Price: " << trade.price 
                  << ", Volume: " << trade.volume << "\n";
    }

    return 0;
}