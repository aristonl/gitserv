#include <git2.h>
#include <iostream>

#include <gitserv.h>

int setup()
{
	git_libgit2_init();

	// Creates the default git directory
	git_repository* repo;
	git_repository_init(&repo, "/srv/git/git/config.git", 0);
	if (repo == NULL) {
		return 1;
		printf("Error creating repository.\n");
	} else {
		printf("Repository created.\n");
	}
}