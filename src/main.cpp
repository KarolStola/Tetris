//
//  main.cpp
//  Tetris
//
//  Created by Karol Stola on 28.03.2014.
//  Copyright (c) 2014 Karol Stola. All rights reserved.
//

#include <iostream>
#include <unistd.h>
#include "logic/Tetris.h"
#include "exceptions/TetrisException.h"

#ifdef __APPLE__
#include "CoreFoundation/CoreFoundation.h"
#endif

void setWorkdir(){
#ifdef __APPLE__
    CFBundleRef mainBundle = CFBundleGetMainBundle();
    CFURLRef resourcesURL = CFBundleCopyResourcesDirectoryURL(mainBundle);
    char path[PATH_MAX];
    if (!CFURLGetFileSystemRepresentation(resourcesURL, TRUE, (UInt8 *)path, PATH_MAX))
    {
        throw TetrisException("Could not initialize workdir.");
    }
    CFRelease(resourcesURL);
	
    chdir(path);
#endif
}

int main(int argc, char* argv[]){
	

	try {
		setWorkdir();
		
		Tetris tetris;
		tetris.play();
	}
	catch (TetrisException& e) {
		std::cerr << "Tetris exception occured:\n" << e.what();
	}
	catch (std::exception& e){
		std::cerr << "Standard exception occured: \n" << e.what();
	}
}
