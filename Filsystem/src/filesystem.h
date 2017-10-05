#ifndef FILESYSTEM_H
#define FILESYSTEM_H

#include "memblockdevice.h"

class FileSystem
{
private:
    MemBlockDevice mMemblockDevice;
    int source;
    int nextFreeBlock;
    // Here you can add your own data structures
public:
    FileSystem(int source = 0, int nextFreeBlock = 0);
    ~FileSystem();

    /* These API functions need to be implemented
	   You are free to specify parameter lists and return values
    */

    /* This function creates a file in the filesystem */
    bool createFile(std::string fpath, std::string filename);

    /* Creates a folder in the filesystem */
    bool createFolder(std::string fpath, std::string foldername);

    /* Removes a file in the filesystem */
    bool removeFile(std::string fpath, std::string filename);

    /* Removes a folder in the filesystem */
    bool removeFolder(std::string fpath, std::string foldername);

    /* Function will move the current location to a specified location in the filesystem */
    void goToFolder(std::string fpath);

    /* This function will get all the files and folders in the specified folder */
    void listDir();

    int seekFolder(std::string folderName);
    /* Add your own member-functions if needed */

    int pwd();
};

#endif // FILESYSTEM_H
