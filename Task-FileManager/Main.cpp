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

    while (true) {
        showMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:  // Show disk content
            cout << "Enter path (e.g., C:/Users/YourUsername/Documents): "; //if doesn't specify, will go into project directory
            cin >> path;
            fm.showDiskContent(path);
            break;
        case 2:  // Create file
            cout << "Enter file path (e.g., C:/Users/YourUsername/Documents/newfile.txt): "; //if doesn't specify, will go into project directory
            cin >> path;
            fm.createFile(path);
            break;
        case 3:  // Create folder
            cout << "Enter folder path (e.g., C:/Users/YourUsername/Documents/newfolder): ";
            cin >> path;
            fm.createFolder(path);
            break;
        case 4:  // Delete file
            cout << "Enter file path (e.g., C:/Users/YourUsername/Documents/newfile.txt): ";
            cin >> path;
            fm.deleteFile(path);
            break;
        case 5:  // Delete folder
            cout << "Enter folder path (e.g., C:/Users/YourUsername/Documents/newfolder): ";
            cin >> path;
            fm.deleteFolder(path);
            break;
        case 6:  // Rename file/folder
            cout << "Enter current path (e.g., C:/Users/YourUsername/Documents/oldname.txt): ";
            cin >> path;
            cout << "Enter new path (e.g., C:/Users/YourUsername/Documents/newname.txt): ";
            cin >> newPath;
            fm.renameFile(path, newPath);
            break;
        case 7:  // Copy file
            cout << "Enter source path (e.g., C:/Users/YourUsername/Documents/file.txt): ";
            cin >> path;
            cout << "Enter destination path (e.g., C:/Users/YourUsername/Documents/backup/file.txt): ";
            cin >> newPath;
            fm.copyFile(path, newPath);
            break;
        case 8:  // Move file
            cout << "Enter source path (e.g., C:/Users/YourUsername/Documents/file.txt): ";
            cin >> path;
            cout << "Enter destination path (e.g., C:/Users/YourUsername/Documents/archive/file.txt): ";
            cin >> newPath;
            fm.moveFile(path, newPath);
            break;
        case 9:  // Calculate size
            cout << "Enter folder/file path (e.g., C:/Users/YourUsername/Documents/file.txt): ";
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
            cout << "Enter folder path (e.g., C:/Users/YourUsername/Documents): ";
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