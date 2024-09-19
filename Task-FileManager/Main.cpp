#include <iostream>
#include "FileManager.h"
using namespace std;

void showMenu() {
    cout << "Choose an option:\n";
    cout << "1. Show disk content\n";
    cout << "2. Create file\n";
    cout << "3. Create folder\n";
    cout << "4. Delete file\n";
    cout << "5. Delete folder\n";
    cout << "6. Rename file/folder\n";
    cout << "7. Copy file\n";
    cout << "8. Move file\n";
    cout << "9. Calculate folder/file size\n";
    cout << "10. Search by mask\n";
    cout << "11. Exit\n";
}

int main() {
    FileManager fm;
    int choice = 0;
    string path, newPath, mask;
    string message = "(e.g., C:/Users/YourUsername/Documents/";

    while (true) {
        showMenu();
        
        while (true) {
            std::cout << "Enter your choice: ";
            std::cin >> choice;

            // Check if the input is valid
            if (std::cin.fail()) {
                std::cin.clear(); // Clear the error flag
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
                std::cout << "Invalid input. Please enter an integer." << std::endl;
            }
            else {
                // If input is valid, break the loop
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear the input buffer
                break; // Exit the loop
            }
        }
        

        switch (choice) {
        case 1:  // Show disk content
            cout << "Enter path (e.g., C:/Users/YourUsername/Documents): "; //if doesn't specify, will go into project directory
            cin >> path;
            try {
                fm.showDiskContent(path);
            }
            catch (const std::runtime_error& e) {
                std::cerr << e.what() << std::endl; // Handle the error message
            }
            
            break;
        case 2:  // Create file
            cout << "Enter file path " + message + "newfile.txt): "; //if doesn't specify, will go into project directory
            cin >> path;
            fm.createFile(path);
            break;
        case 3:  // Create folder
            cout << "Enter folder path " + message + "newfolder): ";
            cin >> path;
            fm.createFolder(path);
            break;
        case 4:  // Delete file
            cout << "Enter file path " + message + "newfile.txt): ";
            cin >> path;
            fm.deleteFile(path);
            break;
        case 5:  // Delete folder
            cout << "Enter folder path " + message + "newfolder): ";
            cin >> path;
            fm.deleteFolder(path);
            break;
        case 6:  // Rename file/folder
            std::cout << "Enter current path " + message + "oldname.txt): ";
            std::cin >> path;
            std::cout << "Enter new path " + message + "newname.txt): ";
            std::cin >> newPath;
            try {
                fm.renameFile(path, newPath);
            }
            catch (const std::runtime_error& e) {
                std::cerr << e.what() << std::endl; // Handle the error message
            }
            break;
        case 7:  // Copy file
            std::cout << "Enter source path " + message + "file.txt): ";
            std::cin >> path;
            std::cout << "Enter destination path " + message + "file.txt): ";
            std::cin >> newPath;
            try {
                fm.copyFile(path, newPath);
            }
            catch (const std::runtime_error& e) {
                std::cerr << e.what() << std::endl; // Handle the error message
            }
            break;
        case 8:  // Move file
            std::cout << "Enter source path " + message + "file.txt: ";
            std::cin >> path;
            std::cout << "Enter destination path " + message + "archive / file.txt): ";
            std::cin >> newPath;
            try {
                fm.moveFile(path, newPath);
            }
            catch (const std::runtime_error& e) {
                std::cerr << e.what() << std::endl; // Handle the error message
            }
            break;
        case 9:  // Calculate size
            cout << "Enter folder/file path " + message + "file.txt): ";
            cin >> path;
            try {
                size_t size = fm.calculateSize(path);  // Store and output size
                cout << "Total size: " << size << " bytes" << endl;
            }
            catch (const std::exception& e) {
                cout << "Error calculating size: " << e.what() << endl;
            }
            break;
        case 10:  // Search by mask
            cout << "Enter folder path " + message + ": ";
            cin >> path;
            cout << "Enter file mask (e.g., .*.txt, .*.docx , .*.pdf): "; //Ensure proper regex mask
            cin >> mask;
            try {
                fm.searchByMask(path, mask);  // Execute search
            }
            catch (const std::exception& e) {
                cout << "Error during search: " << e.what() << endl;
            }
            break;
        case 11:  // Exit
            cout << "Exiting...\n";
            return 0;
        default:
            cout << "Invalid choice. Try again.\n";
        }
    }


	return 0;
}