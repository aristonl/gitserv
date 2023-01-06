#include <git2.h>
#include <iostream>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <gitserv.h>

int authorizePubKey(char* publicKeyPath) {
    // Open public key file
    FILE* keyFile = fopen(publicKeyPath, "r");
    if (keyFile == NULL) {
        printf("Cannot open public key file. This may be an issue with the mode of the file.\n");
        return -1;
    }

    char* homeDir = getenv("HOME");
    if (strcmp(homeDir, "/root") == 0) {
        printf("Cannot run as root. Please run as user 'git' or any other user.\n");
        return -1;
    }

    char* authorizedKeysPath =
    strcpy(authorizedKeysPath, homeDir);
    strcat(authorizedKeysPath, "/.ssh/authorized_keys");
    FILE* authKeysFile = fopen(authorizedKeysPath, "w");
    if (authKeysFile == NULL) {
        printf("Could not open $HOME/.ssh/authorized_keys.");
        return -1;
    }

    char buffer[1024];
    size_t bytesRead;

    while((bytesRead = fread(buffer, 1, sizeof(buffer), keyFile)) > 0)
        fwrite(buffer, 1, bytesRead, authKeysFile);
}

int setup(char* publicKeyPath) {
    git_libgit2_init();

    authorizePubKey(publicKeyPath);

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