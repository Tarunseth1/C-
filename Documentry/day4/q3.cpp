//Bubble Sort

#include <iostream>
#include <vector>
#include <algorithm>

struct Content {
    std::string title;     // Title of the content
    int views;             // Number of views
    double rating;         // User rating
    int releaseYear;       // Release year
};

// Function to calculate a popularity score based on views and recency
double calculateScore(int views, int releaseYear) {
    int currentYear = 2024; // Current year
    return views * 0.7 + (currentYear - releaseYear) * 0.3; // Weighted score formula
}

// Bubble Sort function to sort the catalog
void bubbleSort(std::vector<Content>& catalog) {
    int n = catalog.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            // Calculate scores for comparison
            double scoreA = calculateScore(catalog[j].views, catalog[j].releaseYear);
            double scoreB = calculateScore(catalog[j + 1].views, catalog[j + 1].releaseYear);

            // Swap if the first score is less than the second
            if (scoreA < scoreB) {
                std::swap(catalog[j], catalog[j + 1]);
            }
        }
    }
}

int main() {
    // Sample catalog of movies and shows
    std::vector<Content> catalog = {
        {"Movie A", 5000, 4.5, 2020},
        {"Movie B", 10000, 4.8, 2023},
        {"Show C", 7000, 4.3, 2022},
        {"Show D", 3000, 4.7, 2019},
        {"Movie E", 9000, 4.6, 2021}
    };

    // Sort catalog using Bubble Sort based on calculated score
    bubbleSort(catalog);

    // Display sorted catalog
    std::cout << "Recommended Content:\n";
    for (const auto& item : catalog) {
        std::cout << "Title: " << item.title 
                  << ", Views: " << item.views 
                  << ", Rating: " << item.rating 
                  << ", Release Year: " << item.releaseYear << "\n";
    }

    return 0;
}