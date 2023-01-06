#include <git/git.h>

#include <git2.h>

#include <cstdio>
#include <cstring>
#include <dirent.h>
#include <stdlib.h>
#include <string>
#include <sys/stat.h>
#include <unistd.h>

/*
 * The way the /srv/git directory is structured is as follows:
 * /srv/git
 * |--/user1
 * |  |--/repo1.git
 * |  |--/repo2.git
 * |--/user2
 * |  |--/repo1.git
 * |  |--/repo2.git
 * |--/org
 *    |--/repo1.git
 */

int initRepos()
{
	git_libgit2_init();

	// const char* gitRepoLoc = "/srv/git";
	const std::string gitRepoLoc = "/srv/git";

	struct stat sb;

	if (stat(gitRepoLoc.c_str(), &sb) == 0) {
		printf("Found /srv/git.\n");
	} else {
		printf("Cannot find /srv/git. Creating the directory...");
		if (mkdir(gitRepoLoc.c_str(), 0700) == 0) {
			printf("Created /srv/git. Continuing...\n");
		} else {
			printf("Cannot create /srv/git. Either create this yourself or run "
				   "as sudo/root.\n");
			return -1;
		}
	}

	// Enter /srv/git
	DIR* dir = opendir(gitRepoLoc.c_str());
	if (dir == NULL) {
		printf("Cannot open /srv/git. Make sure you are running with sudo or "
			   "as root.\n");
		return -1;
	}

	// Go thru the user folders in /srv/git
	struct dirent* ent;
	while ((ent = readdir(dir)) != NULL) {
		if (strcmp(ent->d_name, ".") == 0 || strcmp(ent->d_name, "..") == 0) {
			continue;
		}

		if (ent->d_type == DT_DIR) {
			std::string userFolder = gitRepoLoc + "/" + ent->d_name;
			printf("Found user folder: %s\n", userFolder.c_str());
			if (chdir(userFolder.c_str()) != 0) {
				printf("Cannot change to user folder: %s. Make sure you are "
					   "running with sudo or as root.\n",
					userFolder.c_str());
				return -1;
			}

			DIR* userDir = opendir(userFolder.c_str());
			if (userDir == NULL) {
				printf("Cannot open user folder: %s. Make sure you are running "
					   "with sudo or as root.\n",
					userFolder.c_str());
				return -1;
			}

			struct dirent* userEnt;
			while ((userEnt = readdir(userDir)) != NULL) {
				if (strcmp(userEnt->d_name, ".") == 0
					|| strcmp(userEnt->d_name, "..") == 0) {
					continue;
				}

				// FIXME: This currently doesn't iterate thru *every*
				// directory/repository in a user's folder.
				if (userEnt->d_type == DT_DIR) {
					git_repository* repository;
					std::string repoFolder = userFolder + "/" + userEnt->d_name;
					printf("Found repo folder: %s\n", repoFolder.c_str());
					int error
						= git_repository_open(&repository, repoFolder.c_str());
					if (error < 0) {
						printf("Failed to open repository: %s\n",
							repoFolder.c_str());
						return 1;
					}

					// Check if the repository is a bare repository
					bool is_bare = git_repository_is_bare(repository);
					if (is_bare) {
						printf("Repository is bare.\n");
					} else {
						printf("Repository is not bare.\n");
					}

					return 0;
				}
			}
		} else {
			printf("Cannot find any user directories.\n");
		}
	}

	return 0;
}
