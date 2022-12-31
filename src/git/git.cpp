#include <git/git.h>

#include <sys/stat.h>
#include <cstdio>

int initRepos() {
	const char* gitRepoLoc = "/srv/git";

	struct stat sb;

	if (stat(gitRepoLoc, &sb) == 0) {
		printf("Found /srv/git.");
	} else {
		printf("Cannot find /srv/git. Creating the directory...");
		if (mkdir(gitRepoLoc, 0700) == 0) {
			printf("Created /srv/git. Continuing...\n");
		} else {
			printf("Cannot create /srv/git. Either create this yourself or run as sudo/root.\n");
			return -1;
		}
	}
	
	return 0;
}
