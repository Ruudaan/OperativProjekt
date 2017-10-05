#include "filesystem.h"

FileSystem::FileSystem(int source, int nextFreeBlock) {
this->source = source;
this->nextFreeBlock = nextFreeBlock;
}

FileSystem::~FileSystem() {

}





/* Please insert your code */
int FileSystem::pwd()
{
	int blockNr = this->source;
	Block aBlock = this->mMemblockDevice.readBlock(blockNr);
	blockNr = aBlock[4];
	return blockNr;

}
bool FileSystem::createFile(std::string fpath, std::string filename)
{
	return false;
}


bool FileSystem::createFolder(std::string fpath, std::string foldername){
	if(this->nextFreeBlock != 251)
	{

		int parentBlockNr = this->source;
		int nextBlockNr = this->nextFreeBlock;
		Block theBlock = this->mMemblockDevice.readBlock(nextBlockNr);
		Block parentBlock = this->mMemblockDevice.readBlock(parentBlockNr);
		theBlock[0] = 1;
		theBlock[4] = (Block)parentBlock;
		char *c = foldername.c_str();
		Block blockArr = c;

		for(int i = 1; i < 4; i++)
		{
				theBlock[i] = blockArr[i-1];
		}

		for(int i = 5; i < 512; i++)
		{
			if (parentBlock[i] == 0)
			{
				parentBlock[i] = (Block)nextBlockNr;
				i=512;
			}
		}
		std::cout << "Folder has been created " << std::endl;
		this->nextFreeBlock++;
		this->mMemblockDevice.writeBlock(nextBlockNr,theBlock);
		this->mMemblockDevice.writeBlock(parentBlockNr,parentBlock);

	}


	return false;
}

bool FileSystem::removeFile(std::string fpath, std::string filename){
	return false;
}


bool FileSystem::removeFolder(std::string fpath, std::string foldername){
return false;
}


void FileSystem::goToFolder(std::string fpath){

}


void FileSystem::listDir(){

}

int FileSystem::seekFolder(std::string folderName)
{
	int blockNr = this->source;


	return 0;
}
