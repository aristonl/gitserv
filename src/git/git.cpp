#include <git/git.h>

#include <dirent.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <cstdio>
#include <string>
#include <cstring>

int initRepos() {
	//const char* gitRepoLoc = "/srv/git";
	const std::string gitRepoLoc = "/srv/git";

	struct stat sb;

	if (stat(gitRepoLoc.c_str(), &sb) == 0) {
		printf("Found /srv/git.\n");
	} else {
		printf("Cannot find /srv/git. Creating the directory...");
		if (mkdir(gitRepoLoc.c_str(), 0700) == 0) {
			printf("Created /srv/git. Continuing...\n");
		} else {
			printf("Cannot create /srv/git. Either create this yourself or run as sudo/root.\n");
			return -1;
		}
	}

	DIR* dir = opendir(gitRepoLoc.c_str());
 	if (dir == nullptr) {
    	printf("Error: Failed to open /srv/git.\n");
    	return -1;
  	}

	// Iterate over the folders in the root directory
  	struct dirent* entry;
  	while ((entry = readdir(dir)) != nullptr) {
    	// Skip . and .. entries
    	if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
      		continue;
    	}

    	// Check if the current entry is a folder
    	if (entry->d_type == DT_DIR) {
      		// Change to the folder
      		std::string folderPath = gitRepoLoc + "/" + entry->d_name;
      		if (chdir(folderPath.c_str()) != 0) {
        		//std::cerr << "Error: Failed to change to directory '" << folder_path << "'" << std::endl;
				printf("Error: Falied to change to directory '%s'.", folderPath);
        		continue;
      		}

      		// Check if the folder is a bare repository
      		int result = system("git rev-parse --is-bare-repository");
      		if (result == 0) {
        		//std::cout << "The folder '" << folder_path << "' is a bare repository" << std::endl;
				printf("Discovered repository '%s'", folderPath);
      		} else {
     			//std::cout << "The folder '" << folder_path << "' is not a bare repository" << std::endl;
				printf("Folder '%s' isn't a Git repository. Skipping...", folderPath);
      		}
   	 	}
	}

  	closedir(dir);

	return 0;
}
