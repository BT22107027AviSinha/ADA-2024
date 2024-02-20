#include <iostream>

const int MAX_SIZE = 11; // Maximum size of the data array

// Function to insert data into the array
void Insert_data(int data[], int& size, int value) {
    if (size < MAX_SIZE) {
        data[size++] = value;
    }
}

// Function to perform linear search
bool linear_search(const int data[], int size, int key) {
    for (int i = 0; i < size; i++) {
        if (data[i] == key) {
            return true;
        }
    }
    return false;
}

// Function to display the data
void display(const int data[], int size) {
    std::cout << "Data: ";
    for (int i = 0; i < size; i++) {
        std::cout << data[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    int data[MAX_SIZE];
    int size = 0;

    // Insert data into the array
    Insert_data(data, size, 2);
    Insert_data(data, size, 5);
    Insert_data(data, size, 7);
    Insert_data(data, size, 7);
    Insert_data(data, size, 8);
    Insert_data(data, size, 10);
    Insert_data(data, size, 18);
    Insert_data(data, size, 28);
    Insert_data(data, size, 31);
    Insert_data(data, size, 57);
    Insert_data(data, size, 81);

    // Display the data
    display(data, size);

    // Perform linear search
    std::cout << "Searching for 2: " << (linear_search(data, size, 2) ? "Found" : "Not Found") << std::endl;
    std::cout << "Searching for 81: " << (linear_search(data, size, 81) ? "Found" : "Not Found") << std::endl;
    std::cout << "Searching for 7: " << (linear_search(data, size, 7) ? "Found" : "Not Found") << std::endl;
    std::cout << "Searching for 3: " << (linear_search(data, size, 3) ? "Found" : "Not Found") << std::endl;

    return 0;
}
